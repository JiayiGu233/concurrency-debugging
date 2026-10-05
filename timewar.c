#define _GNU_SOURCE
#define HASH_BUFFER_LENGTH 32

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <string.h>
#include <openssl/sha.h>

void read_data(char* destination, unsigned int generator_seed);
void process(int* input);
int* calculate(char* input_buffer);

const int num_doctors = 13;
pthread_t doctors[13];

pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_barrier_t barrier;

int* coordinates;
int ready;



void* first_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Calling the war council of Gallifrey...\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }

    pthread_mutex_lock(&lock1);
    pthread_mutex_lock(&lock2);
    read_data(input, 252);
    int* c = calculate(input);
    if (c != NULL) {
        coordinates[0] += *c;
        free(c); 
    }
    ready++;
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    free(input);
    pthread_exit(NULL); 
}

void* second_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("This is the Doctor!\n");

    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 477);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[0] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* third_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Ready!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 482);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[0] += *c;
        pthread_mutex_unlock(&lock2);
        free(c); 
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* fourth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Commencing Calculations...\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 839);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[0] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input); 

    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* fifth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Nearly there?\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 178);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[1] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* sixth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Just about!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 970);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[1] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* seventh_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Cross the boundaries that divide one universe from another...\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 235);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[1] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* eighth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Lock on to these coordinates!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 919);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[1] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* war_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Oh for gods' sake... Gallifrey stands!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 93);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[2] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    int* count = malloc(sizeof(int));
    if (count == NULL) {
        perror("Failed to allocate memory for count");
        pthread_exit(NULL);
    }
    process(count);
    free(count);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* ninth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("And for my next trick...!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 57);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[2] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* tenth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("Allons-y!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 712);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[3] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* eleventh_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    printf("GERONIMO!\n");
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 272);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock2);
        coordinates[3] += *c;
        pthread_mutex_unlock(&lock2);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void* twelfth_doctor(void* arg) {
    pthread_barrier_wait(&barrier);
    char* input = malloc(33);
    if (input == NULL) {
        perror("Failed to allocate memory for input");
        pthread_exit(NULL);
    }
    read_data(input, 647);
    int* c = calculate(input);
    if (c != NULL) {
        pthread_mutex_lock(&lock1);
        pthread_mutex_lock(&lock2);
        coordinates[3] += *c;
        pthread_mutex_unlock(&lock2);
        pthread_mutex_unlock(&lock1);
        free(c);
    }
    free(input);
    pthread_mutex_lock(&lock1);
    ready++;
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

void gather_doctors();
void wait_until_done();
bool verify_coordinates();

int main(int argc, char** argv) {
    ready = 0;
    coordinates = calloc(4, sizeof(int));
    if (coordinates == NULL) {
        perror("Failed to allocate memory for coordinates");
        return EXIT_FAILURE;
    }
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    pthread_barrier_init(&barrier, NULL, num_doctors);
    gather_doctors();
    wait_until_done();
    int final_ready;
    pthread_mutex_lock(&lock1);
    final_ready = ready;
    pthread_mutex_unlock(&lock1);

    if (verify_coordinates() && final_ready == num_doctors) {
        printf("Gallifrey Stands!\n");
    } else {
        printf("Gallifrey falls...\n");
    }

    free(coordinates);
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    pthread_barrier_destroy(&barrier);
    return 0;
}

void gather_doctors() {
    pthread_create(&doctors[0], NULL, first_doctor, NULL);
    pthread_create(&doctors[1], NULL, second_doctor, NULL);
    pthread_create(&doctors[2], NULL, third_doctor, NULL);
    pthread_create(&doctors[3], NULL, fourth_doctor, NULL);
    pthread_create(&doctors[4], NULL, fifth_doctor, NULL);
    pthread_create(&doctors[5], NULL, sixth_doctor, NULL);
    pthread_create(&doctors[6], NULL, seventh_doctor, NULL);
    pthread_create(&doctors[7], NULL, eighth_doctor, NULL);
    pthread_create(&doctors[8], NULL, war_doctor, NULL);
    pthread_create(&doctors[9], NULL, ninth_doctor, NULL);
    pthread_create(&doctors[10], NULL, tenth_doctor, NULL);
    pthread_create(&doctors[11], NULL, eleventh_doctor, NULL);
    pthread_create(&doctors[12], NULL, twelfth_doctor, NULL);
}

void wait_until_done() {
    for (int i = 0; i < num_doctors; ++i) {
        pthread_join(doctors[i], NULL);
    }
}

void read_data(char* dest, unsigned int generator_seed) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < HASH_BUFFER_LENGTH; ++i) {
        dest[i] = alphanum[rand_r(&generator_seed) % (sizeof(alphanum) - 1)];
    }
    dest[HASH_BUFFER_LENGTH] = '\0';
}

int* calculate(char* input_buffer) {
    int* res = malloc(sizeof(int));
    if (res == NULL) {
        perror("Failed to allocate memory for res");
        return NULL;
    }
    unsigned char* output_buffer = calloc(HASH_BUFFER_LENGTH, sizeof(unsigned char));
    if (output_buffer == NULL) {
        perror("Failed to allocate memory for output_buffer");
        free(res);
        return NULL;
    }
    SHA256((unsigned char*)input_buffer, HASH_BUFFER_LENGTH, output_buffer);
    pthread_t self = pthread_self();
    for (int i = 0; i < num_doctors; ++i) {
        if (pthread_equal(self, doctors[i])) {
            *res = i;
            break;
        }
    }
    free(output_buffer);
    return res;
}

void process(int* input) {
    for (int i = 0; i < 100000000; i++) {
        (*input)++;
    }
}

bool verify_coordinates() {
    pthread_mutex_lock(&lock2);
    bool correct = (coordinates[0] == 6) 
                && (coordinates[1] == 22)
                && (coordinates[2] == 17)
                && (coordinates[3] == 33);
    pthread_mutex_unlock(&lock2);
    return correct;
}
