package com.company;

public class Main {

    public static void main(String[] args)
    {
        int[][] matrix1={{1,5,7},{3,2,4}};
        int[][] matrix2={{1,3},{7,8},{9,5}};
        int[][] matrix3;
        matrix3=MatrisCarpim(matrix1,matrix2,matrix2[0].length);
        for(int i=0;i<matrix3.length;i++)
        {
            for(int j=0;j<matrix3[0].length;j++)
            {
                System.out.print(matrix3[i][j]+" ");
            }
            System.out.println("\n");

        }


    }
    public static int[][] MatrisCarpim(int[][] x,int[][] y,int yLength)
    {
        int araToplam;
        int[][] z=new int[x.length][yLength];
        for(int i=0;i<x.length;i++)
        {
            for(int j=0;j<yLength;j++)
            {
                araToplam=0;
                for(int k=0;k<y.length;k++)
                {
                    araToplam=araToplam+(x[i][k]*y[k][j]);
                }
                z[i][j]=araToplam;
            }
        }
        return z;

    }
}
