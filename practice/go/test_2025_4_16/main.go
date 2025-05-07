package main

import (
	"fmt"
	"sync"
	"time"
)

type Todo struct {
	ID        int
	Title     string
	Completed bool
	CreatedAt time.Time
}

type TodoList struct {
	todos  []Todo
	nextID int
	mu     sync.Mutex
}

func NewTodoList() *TodoList {
	return &TodoList{
		todos:  make([]Todo, 0),
		nextID: 1,
	}
}

func (tl *TodoList) Add(title string) Todo {
	tl.mu.Lock()
	defer tl.mu.Unlock()

	todo := Todo{
		ID:        tl.nextID,
		Title:     title,
		Completed: false,
		CreatedAt: time.Now(),
	}

	tl.todos = append(tl.todos, todo)
	tl.nextID++

	return todo
}

func (tl *TodoList) Complete(id int) error {
	tl.mu.Lock()
	defer tl.mu.Unlock()

	for i := range tl.todos {
		if tl.todos[i].ID == id {
			tl.todos[i].Completed = true
			return nil
		}
	}

	return fmt.Errorf("待办事项ID %d 不存在", id)
}

func (tl *TodoList) List() []Todo {
	tl.mu.Lock()
	defer tl.mu.Unlock()

	result := make([]Todo, len(tl.todos))
	copy(result, tl.todos)

	return result
}

func main() {
	todoList := NewTodoList()

	todoList.Add("学习Go语言基础")
	todoList.Add("掌握Go并发编程")
	todoList.Add("构建Web应用程序")

	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		time.Sleep(500 * time.Millisecond)
		err := todoList.Complete(1)
		if err != nil {
			fmt.Println("错误:", err)
		}
	}()

	wg.Wait()

	fmt.Println("待办事项列表:")
	for _, todo := range todoList.List() {
		status := "[ ]"
		if todo.Completed {
			status = "[✓]"
		}
		fmt.Printf("%s ID:%d - %s (创建于: %s)\n",
			status, todo.ID, todo.Title,
			todo.CreatedAt.Format("2006-01-02 15:04:05"))
	}

	countChan := make(chan int)
	go func() {
		countChan <- len(todoList.List())
	}()

	count := <-countChan
	fmt.Printf("\n总共有 %d 个待办事项\n", count)
}
