#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

#define PING_PONG_LIMIT 11

void print_mpi_basic_infos();

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
        else
        {
            MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process %d received ping pang count %d from process %d\n", world_rank, ping_pong_count, partner_rank);
            // sleep(1);
        }
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}

void print_mpi_basic_infos()
{
    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Running in processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);
}