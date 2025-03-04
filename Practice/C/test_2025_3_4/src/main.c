#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

// 互斥锁用于保护共享资源
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 共享计数器
int counter = 0;

// 线程执行的函数
void* thread_function(void* arg) {
  int thread_id = *(int*)arg;
  int local_count = 0;

  printf("线程 %d 开始运行\n", thread_id);

  // 模拟工作
  for (int i = 0; i < 5; i++) {
    // 随机睡眠0-2秒，模拟不同负载
    int sleep_time = rand() % 3;
    printf("线程 %d 工作中...(%d/5)\n", thread_id, i + 1);
    sleep(sleep_time);
    local_count++;
  }

  // 使用互斥锁保护共享资源的访问
  pthread_mutex_lock(&mutex);
  counter += local_count;
  printf("线程 %d 完成工作，本地计数: %d，全局计数: %d\n", thread_id,
         local_count, counter);
  pthread_mutex_unlock(&mutex);

  // 返回该线程处理的项目数
  int* result = malloc(sizeof(int));
  *result = local_count;
  return (void*)result;
}

int main() {
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];
  int* thread_results[NUM_THREADS];

  printf("主线程: 创建 %d 个工作线程\n", NUM_THREADS);

  // 初始化随机数生成器
  srand(time(NULL));

  // 创建线程
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_ids[i] = i + 1;
    if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) !=
        0) {
      perror("无法创建线程");
      return 1;
    }
  }

  printf("主线程: 等待所有工作线程完成...\n");

  // 等待所有线程完成并收集结果
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

  // 销毁互斥锁
  pthread_mutex_destroy(&mutex);

  return 0;
}