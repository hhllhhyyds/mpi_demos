#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

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

void check_world_size(int n)
{
    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    if (world_size != n)
    {
        // Get the rank of the process
        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
        if (world_rank == 0)
        {
            printf("Error: world size != 2\n");
        }

        // Finalize the MPI environment.
        MPI_Finalize();
        exit(0);
    }
}