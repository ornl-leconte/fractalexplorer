//


#ifndef __MANDELBROT_H__
#define __MANDELBROT_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#include <mpi.h>

#include <time.h>
#include <sys/time.h>
#include <getopt.h>


#include "log.h"
#include "mandelbrot_util.h"

#include "fr.h"


// result from worker
typedef struct fr_wr_t {
    double * _data;

    // hash of cX, cY, Z, etc, so we know when to update
    int hash;
} fr_wr_t;

typedef struct fr_recombo_t {
    int num_workers;
    fr_t * workers;
    fr_wr_t * idata;

    double * _data;

} fr_recombo_t;


typedef struct mandelbrot_argp_t {

     bool show_help;

} mandelbrot_argp_t;


#define mpi_fr_numitems (6)
/*MPI_Datatype mpi_fr_t;
int mpi_fr_blocklengths[mpi_fr_numitems];
MPI_Datatype mpi_fr_types[mpi_fr_numitems];
MPI_Aint mpi_fr_offsets[mpi_fr_numitems];
*/

fr_t fr;
fr_col_t col;
MPI_Datatype mpi_fr_t;


int world_size, world_rank;
#define IS_HEAD (world_rank == 0)
#define IS_COMPUTE (world_rank > 0)

#define compute_size (world_size - 1)
#define compute_rank (world_rank - 1)



int main(int argc, char ** argv);

void start_render();
void start_compute();


#endif
