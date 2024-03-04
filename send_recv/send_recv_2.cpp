#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

#include "basic.h"

#define PING_PONG_LIMIT 11

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    print_mpi_basic_infos();

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int ping_pong_count = 0;
    int partner_rank = (world_rank + 1) % 2;

    while (ping_pong_count < PING_PONG_LIMIT)
    {
        if (world_rank == ping_pong_count % 2)
        {
            ping_pong_count++;
            MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
        }
        else if (world_rank == (ping_pong_count + 1) % 2)
        {
            MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process %d received ping pang count %d from process %d\n", world_rank, ping_pong_count, partner_rank);
            sleep(1);
        }
        else
        {
            break;
        }
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
