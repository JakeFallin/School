//Completed by Jacob Fallin and Justin Miller
//I pledge my honor that I have abided by the Stevens Honor System
//02/21/18

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <errno.h>

#define NUMP 5


pthread_mutex_t fork_mutex[NUMP];
//declare a mutex for eating
pthread_mutex_t eating_m;
//declare a condition for eating
pthread_cond_t eating_c;
//so only 4 can attempt to eat at once
int eating_num = 4;

int main()  
{
  //init the number of philosophers eating to 0
  int i;
  pthread_t diner_thread[NUMP]; 
  int dn[NUMP];
  void *diner();

 //initalize the condition and the mutex
  pthread_cond_init(&eating_c, NULL);
  pthread_mutex_init(&eating_m, NULL);

  for (i=0;i<NUMP;i++)
    pthread_mutex_init(&fork_mutex[i], NULL);

  for (i=0;i<NUMP;i++){
    dn[i] = i;
    pthread_create(&diner_thread[i],NULL,diner,&dn[i]);
  }
  for (i=0;i<NUMP;i++)
    pthread_join(diner_thread[i],NULL);

  for (i=0;i<NUMP;i++)
    pthread_mutex_destroy(&fork_mutex[i]);
  
  pthread_exit(0);

}

void *diner(int *i)
{
  int v;
  int eating = 0;
  printf("I'm diner %d\n",*i);
  v = *i;
  while (eating < 5) {
    printf("%d is thinking\n", v);
    sleep(v / 2);
    printf("%d is hungry\n", v);

    //lock the eating and while there is too many
    //philosophers wait with the condition variable
    pthread_mutex_lock(&eating_m);
    //if there is no one eating then set the wait condition
    //on the mutex
    while(eating_num == 0) {
      pthread_cond_wait(&eating_c, &eating_m);
    }
    
    //decrease the amount eating
    eating_num -= 1;
    //unlock the mutex since we are ready
    pthread_mutex_unlock(&eating_m);

    pthread_mutex_lock(&fork_mutex[v]);
    pthread_mutex_lock(&fork_mutex[(v+1)%NUMP]);

    //increase the number eating
    printf("%d is eating\n", v);
    eating++;
    sleep(1);
    printf("%d is done eating\n", v);

    //while unlocked increase the eating number 
    //if there is only one signal the condition
    pthread_mutex_lock(&eating_m);
    eating_num += 1;
    if(eating_num == 1) {
      pthread_cond_signal(&eating_c);
    }

    //unlock the mutex since we are ready
    pthread_mutex_unlock(&eating_m);
    pthread_mutex_unlock(&fork_mutex[v]);
    pthread_mutex_unlock(&fork_mutex[(v+1)%NUMP]);

    
  }
  pthread_exit(NULL);
}
