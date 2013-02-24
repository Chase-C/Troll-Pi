#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ComputeNewOffset(double r, double val)
{
    return (val + sqrt(2*pow(r, 2) - pow(val, 2))) / 2;
}

double DeltaLength(double x, double y, double c, double d, double s, double t, double r, int depth, int maxDepth)
{
    if(depth >= maxDepth)
       return (sqrt(pow(x - s, 2) + pow(y - d, 2)) + sqrt(pow(x - c, 2) + pow(y - t, 2)));

    double newY1 = ComputeNewOffset(r, d - x);
    double newX2 = ComputeNewOffset(r, c - y);
    double newX1 = x - d + newY1;
    double newY2 = y - c + newX2;

    return (DeltaLength(newX1, newY1, x, d, s, y, r, depth + 1, maxDepth) +
            DeltaLength(newX2, newY2, c, y, x, t, r, depth + 1, maxDepth));
}

double ApproxPi(double r, int maxDepth)
{ 
    double firstPoint = (sqrt(2) / 2) * r;
    double arcLength = DeltaLength(firstPoint, firstPoint, r, r, 0, 0, r, 1, maxDepth);
    return (arcLength * (2/r));
}

int main()
{
    for(;;) {
        printf("Radius: ");
        
        double radius;
        int scanCount = scanf("%lg", &radius);
        if(scanCount == EOF) {
            break;
        } else if(scanCount != 1) {
            fprintf(stderr, "Bad number\n\n");
            exit(EXIT_FAILURE);
        }

        printf("Depth: ");
        
        int depth;
        scanCount = scanf("%i", &depth);
        if(scanCount == EOF) {
            break;
        } else if(scanCount != 1) {
            fprintf(stderr, "Bad number\n\n");
            exit(EXIT_FAILURE);
        }

        double pi = ApproxPi(radius, depth);
        printf("\nPi: %f\n\n", pi);
    }
}
