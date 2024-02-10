#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

void JobSwap(job* a, job* b)
{
    job temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int JobsCompare(job a, job b)
{
    if ((a.profit / a.duration) > (b.profit / b.duration))
    {
        return 1;
    }
    else if ((a.profit / a.duration) < (b.profit) / b.duration)
    {
        return -1;
    }
    else
    {
        return a.duration - b.duration;
    }
}

int ScheduleJobs(const job* jobs, size_t j_size)
{
    int prof_max = 0;
    int scelta = 0;

    int* ordine = calloc(j_size, sizeof(int));
    for (int k = 0; k < j_size; k++)
    {
        ordine[k] = k;
    }

    //ordinamento prioritario
    for (int j = 1; j < j_size; j++)
    {
        if (JobsCompare(jobs[j], jobs[j - 1]) > 0)
        {
            JobSwap(jobs + j, jobs + (j - 1));
            int temp = ordine[j];
            ordine[j] = ordine[j - 1];
            ordine[j - 1] = temp;
        }
    }


    //controllo scadenze
    int tempo_corrente = 0;
    int profitto_totale = 0;
    for (int i = 0; i < j_size; i++)
    {
        if (jobs[i].duration + tempo_corrente <= jobs[i].deadline)
        {
            tempo_corrente += jobs[i].duration;

            profitto_totale += jobs[i].profit;
        }
        else
        {
            ordine[i] = -1;
        }
    }

    for (size_t n = 0; n < j_size; ++n)
    {
        if (ordine[n] >= 0)
        {
            printf("%d ", ordine[n]);
        }
    }

    return profitto_totale;
}


/*
int main()
{
    job jobs[] = { {.duration = 2, .profit = 80, .deadline = 4},
                   {.duration = 5, .profit = 100, .deadline = 6},
                   {.duration = 1, .profit = 30, .deadline = 3} };
    size_t dim = sizeof(jobs) / sizeof(jobs[0]);

    int ris = ScheduleJobs(jobs, dim);
    return 0;
}
*/