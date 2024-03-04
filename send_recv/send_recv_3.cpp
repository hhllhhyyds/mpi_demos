#include <mpi.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "basic.h"

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    check_world_size(2);

    int sent_length;

    if (world_rank == 0)
    {
        const int MAX_NUMBER = 100;
        int numbers[MAX_NUMBER];
        time_t t;
        srand((unsigned)time(&t));
        int rnd = rand() % 9999;
        sent_length = ((float)rnd / (float)9999) * MAX_NUMBER;

        MPI_Send(numbers, sent_length, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("0 sent %d numbers to 1\n", sent_length);
    }
    else if (world_rank == 1)
    {
        MPI_Status status;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &sent_length);

        int *buf = (int *)malloc(sent_length * sizeof(int));
        MPI_Recv(buf, sent_length, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        printf("1 dynamically receive %d from 0, source = %d, tag = %d\n",
               sent_length, status.MPI_SOURCE, status.MPI_TAG);

        free(buf);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
