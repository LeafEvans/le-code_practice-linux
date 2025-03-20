#if false
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void* thread_function(void* arg) {
  int thread_id = *(int*)arg;
  int local_count = 0;

  printf("线程 %d 开始运行\n", thread_id);

  for (int i = 0; i < 5; i++) {
    int sleep_time = rand() % 3;
    printf("线程 %d 工作中...(%d/5)\n", thread_id, i + 1);
    sleep(sleep_time);
    local_count++;
  }

  pthread_mutex_lock(&mutex);
  counter += local_count;
  printf("线程 %d 完成工作，本地计数: %d，全局计数: %d\n", thread_id,
         local_count, counter);
  pthread_mutex_unlock(&mutex);

  int* result = malloc(sizeof(int));
  *result = local_count;
  return (void*)result;
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];
  int* thread_results[NUM_THREADS];

  printf("主线程: 创建 %d 个工作线程\n", NUM_THREADS);

  srand(time(NULL));

  for (int i = 0; i < NUM_THREADS; i++) {
    thread_ids[i] = i + 1;
    if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) !=
        0) {
      perror("无法创建线程");
      return 1;
    }
  }

  printf("主线程: 等待所有工作线程完成...\n");

  int total_processed = 0;
  for (int i = 0; i < NUM_THREADS; i++) {
    if (pthread_join(threads[i], (void**)&thread_results[i]) != 0) {
      perror("无法等待线程");
      return 2;
    }
    total_processed += *thread_results[i];
    free(thread_results[i]);
  }

  printf("主线程: 所有线程已完成\n");
  printf("主线程: 全局计数器值: %d\n", counter);
  printf("主线程: 所有线程处理的项目总数: %d\n", total_processed);

  pthread_mutex_destroy(&mutex);

  return 0;
}
#endif

#if false
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (main)
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    }
    return 0;
}
#endif

#if false
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  printf("hello world (pid:%d)\n", (int)getpid());
  int rc = fork();
  if (rc < 0) {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
    printf("hello, I am child (pid:%d)\n", (int)getpid());
  } else {
    // parent goes down this path (main)
    int wc = wait(NULL);
    printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", rc, wc,
           (int)getpid());
  }
  return 0;
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int x = 100;  // 主进程中的变量 x
  printf("Before fork(): x = %d\n", x);
  int rc = fork();  // 创建子进程
  if (rc < 0) {
    // fork 失败
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // 子进程
    printf("Child process: x = %d\n", x);
    x = 200;  // 子进程修改 x 的值
    printf("Child process: After changing x = %d\n", x);
  } else {
    // 父进程
    printf("Parent process: x = %d\n", x);
    x = 300;
    printf("Parent process: After changing x = %d\n", x);
  }
  return 0;
}