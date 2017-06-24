//AUTHOR: Athish Rahul Rao
//INSTITUTION: Mahindra Ecole Centrale, Hyderabad, India

#include <iostream>
//This code uses variadic templates to detect elements at predefined positions in a sparse matrix during complile time
//This has been specifically written for a 5x5 matrix
//This can be extended and made generic to anjy nxn matrix by changing a few variables
//The position of the elements have been inputted in such a linear manner and not by using matrix positions
//This is a trial version and needs refining 

//Base Condition
template<typename T>
int matrix(int mat[5][5], T t){
	int a,b;
	if (t<6){b=t-1;a=0;}
	else{a = (t-1)/5; b = (t- ((t-1)/5)*5) - 1; }
	//Verification- To see if the non-zero elements are detected 
	std::cout << "a:" << a << "   b:" << b << "  t:" << t << "   Value: " << mat[a][b]  << std::endl ;
	return 0;
}

//Variadic Template
template<typename T, typename... Rest>
int matrix(int mat[5][5], T t, Rest... rest ){
	int a,b;
	if (t<6){b=t-1;a=0;}
	else{a = (t-1)/5; b = (t- ((t-1)/5)*5) - 1; }
	//Verification- To see if the non-zero elements are detected 
	std::cout << "a:" << a << "   b:" << b << "  t:" << t << "   Value: " << mat[a][b] << std::endl ;
	matrix(mat, rest...);
	return 0;

}
 
int main(){
	//Sparse 5x5 matrix
	int mat[5][5] = { {1,0,0,0,0},{1,1,0,0,0},{0,1,1,0,0},{0,1,1,1,0},{0,0,1,1,1} };
	//Inputs of the function are the positions whre the non zero enities are present
	matrix(mat,1,6,7,12,13,17,18,19,23,24,25);
	return 0;
}
