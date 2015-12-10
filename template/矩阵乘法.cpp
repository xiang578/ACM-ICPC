struct Mat
{
    double mat[N][N];
};
Mat operator * (Mat a, Mat b)
{
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for(k = 0; k < n; ++k)
    {
        for(i = 0; i < n; ++i)
        {

            for(j = 0; j < n; ++j)
            {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}
Mat operator ^ (Mat a, int k)
{
    Mat c;
    int i, j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            c.mat[i][j] = (i == j);    //初始化为单位矩阵

    for(; k; k >>= 1)
    {
        if(k&1) c = c*a;

        a = a*a;
    }
    return c;
}
