struct timeval startMdlDestroy;
struct timeval finishMdlDestroy;
gettimeofday( &startMdlDestroy, NULL );
msgReturnIfError( analExtPreAccept( gCircuit->Analysis,
            Time->Real, gCircuit->Solution ) );
gettimeofday( &finishMdlDestroy, NULL );
double elapse = ( double )( finishMdlDestroy.tv_sec - startMdlDestroy.tv_sec ) +
( double )( finishMdlDestroy.tv_usec - startMdlDestroy.tv_usec ) * 1e-6; 
static double sum = 0;
sum += elapse;
static unsigned int mdlCount = 0;
if ( 0 == ++mdlCount % 500 ) 
{
    msgWrite(msgWarning, "preAccept use time %e s \n", sum );
    sum = 0.0;
}

