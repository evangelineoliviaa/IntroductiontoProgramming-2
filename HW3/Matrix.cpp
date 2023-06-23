#include<iostream>

using namespace std;
class Matrix
{
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    friend std::istream &operator>>(std::istream &, Matrix &);
public:
    Matrix(int s = 5);

    Matrix(const Matrix &);// copy constructor

    ~Matrix();

    Matrix &operator=(const Matrix &a);

    Matrix &clockwise90();
private:
    int **matrix;
    int *buf;   // 2D matrix stored in 1D raster scan order
    int size;
}; //end class Matrix
Matrix :: Matrix(int s){
    size = s;
    buf = new int[size*size];
    matrix = new int*[size];
    for(int i = 0; i<size;i++)
    {
        matrix[i]=new int[size];
    }
}
Matrix :: Matrix(const Matrix &a)
{

}
Matrix :: ~Matrix() {
    delete [] matrix;
    delete [] buf;
}
std::ostream &operator<<(std::ostream &output, const Matrix &a)
{
    for(int i = 0 ; i<a.size; i++)
    {
        for(int j = 0; j<a.size; j++)
        {
            if(j==a.size-1){
                output<<a.matrix[i][j];
            }else{
                output<<a.matrix[i][j]<<" ";
            }
        }output<<endl;
    }
    return output;
}
std::istream &operator>>(std::istream &input, Matrix &a)
{
    for(int i = 0; i<a.size;i++){
        for(int j = 0; j<a.size; j++)
        {
            input>>a.matrix[i][j];
        }
    }
    return input;
}
Matrix &Matrix :: clockwise90(){
        int tmp[size*size];
        int num = 0;
        for(int i=0;i<this->size;i++){
            for(int j = 0;j<this->size;j++){
                tmp[num] = this->matrix[i][j];
                num++;
            }
        }
        num=0;
        for(int i=size-1; i>=0; i--){
            for(int j=0; j<size; j++){
                matrix[j][i] = tmp[num];
                num++;
            }
        }
        return *this;
    }
int main()
{
    int matrix_size;
    cin>>matrix_size;

    Matrix a(matrix_size);
    cin>>a;

    cout<<endl;
    cout<<a.clockwise90().clockwise90()<<endl;
    cout<<a<<endl;

    return 0;
}