void eratosfen( int n )
{

    bool a[n];

    a[0] = false;

    a[1] = false;

    for ( int i = 2; i <= n; i++ )

        a[i] = true;

    int p = 2;

    while ( p*p <= n)

    {

        if( a[p] )

        {

            for( int i = p*p; i <= n; i = i + p )

            a[i] = false;

        }

        p++;

    }

    for ( int i = 2; i <= n; i++ )

        if (a[i])

            cout << i << "; ";

}

int main()
{

    int number;

    cin>>number;

    eratosfen(number);

    return 0;

} 
