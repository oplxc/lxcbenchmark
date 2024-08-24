#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 5

int sid;
void lxcfs_test(const char *lxcfile) {
FILE *src;
char buffer[512];
int sbuf=0;
while (sid>0){
src = fopen(lxcfile, "rb");
if (src == NULL) {
perror("can open lxcfs");
continue;}
FILE *null = fopen("/dev/null", "wb");
if (null == NULL) {
perror("Error opening dev");
fclose(src);
continue;}
if (sbuf=fread(buffer, 1, sizeof(buffer), src) > 0){fwrite(buffer, 1, sbuf, null);usleep(NUM_THREADS*512);}
fclose(src);
fclose(null);}}
void* _pthread_exit(void* arg) {
int tid = *((int*)arg);
if (tid==0){tid=sid;sid++;}
printf("INFO: thread %d start\n",tid);
if (tid==1){
lxcfs_test("/proc/meminfo");
} else if (tid==2) {
lxcfs_test("/proc/stat");
} else if (tid==3) {
lxcfs_test("/proc/uptime");
} else if (tid==4) {
lxcfs_test("/proc/cpuinfo");
}
printf("INFO: thread %d exit...\n",tid);
return NULL;
}
int main(int argc, char *argv[]) {
if ((argc == 2) && *(argv[1]+1)=='h') {
fprintf(stderr, "usage: %s \nvar: export thd=1 -> set therad=1;\nrecommand thread=cpu Num\n", argv[0]);
return EXIT_FAILURE;}
pthread_t threads[NUM_THREADS];
int threadIDs[NUM_THREADS+1];
char htherad=1;;
char *ethread;
sid=1;
ethread = getenv("thd");
for (int i = 1; i < 5; i++) {
threadIDs[i]=i;}
if (ethread != NULL) {
htherad=atoi(ethread);}
if (pthread_create(&threads[1], NULL, _pthread_exit, (void*)&threadIDs[1]) != 0) {printf("Failed to create thd id: %d\n",threadIDs[1]);}
if (htherad>1){
if (pthread_create(&threads[2], NULL, _pthread_exit, (void*)&threadIDs[2]) != 0) {printf("Failed to create thd id: %d\n",threadIDs[2]);}}
if (htherad>2){
if (pthread_create(&threads[3], NULL, _pthread_exit, (void*)&threadIDs[3]) != 0) {printf("Failed to create thd id: %d\n",threadIDs[3]);}}
if (htherad>3){
if (pthread_create(&threads[4], NULL, _pthread_exit, (void*)&threadIDs[4]) != 0) {printf("Failed to create thd id: %d\n",threadIDs[4]);}}
if (htherad>4){htherad=4;}
for (int i = 0; i < htherad; i++) {
pthread_join(threads[i], NULL);
}
return 0;
}
