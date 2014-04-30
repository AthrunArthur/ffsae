#include <iostream>
#include <matio.h>
#include <map>
#include <string>

std::map<matio_types, std::string> type_str ={
    {MAT_T_UNKNOWN, "MAT_T_UNKNOWN"},
    {MAT_T_INT8, "MAT_T_INT8"},
    {MAT_T_UINT8, "MAT_T_UINT8"},
    {MAT_T_INT16, "MAT_T_INT16"},
    {MAT_T_UINT16, "MAT_T_UINT16"},
    {MAT_T_INT32, "MAT_T_INT32"},
    {MAT_T_UINT32, "MAT_T_UINT32"},
    {MAT_T_SINGLE, "MAT_T_SINGLE"},
    {MAT_T_DOUBLE, "MAT_T_DOUBLE"},
    {MAT_T_INT64, "MAT_T_INT64"},
    {MAT_T_MATRIX, "MAT_T_MATRIX"},
    {MAT_T_COMPRESSED, "MAT_T_COMPRESSED"},
    {MAT_T_UTF8, "MAT_T_UTF8"},
    {MAT_T_UTF16, "MAT_T_UTF16"},
    {MAT_T_UTF32, "MAT_T_UTF32"},
    {MAT_T_STRING, "MAT_T_STRING"},
    {MAT_T_CELL, "MAT_T_CELL"},
    {MAT_T_STRUCT, "MAT_T_STRUCT"},
    {MAT_T_ARRAY, "MAT_T_ARRAY"},
    {MAT_T_FUNCTION, "MAT_T_FUNCTION"},
};

std::map<matio_classes, std::string> class_str = {
    {MAT_C_EMPTY, "MAT_C_EMPTY"},
    {MAT_C_CELL, "MAT_C_CELL"},
    {MAT_C_STRUCT, "MAT_C_STRUCT"},
    {MAT_C_OBJECT, "MAT_C_OBJECT"},
    {MAT_C_CHAR, "MAT_C_CHAR"},
    {MAT_C_SPARSE, "MAT_C_SPARSE"},
    {MAT_C_DOUBLE, "MAT_C_DOUBLE"},
    {MAT_C_SINGLE, "MAT_C_SINGLE"},
    {MAT_C_INT8, "MAT_C_INT8"},
    {MAT_C_UINT8, "MAT_C_UINT8"},
    {MAT_C_INT16, "MAT_C_INT16"},
    {MAT_C_UINT16, "MAT_C_UINT16"},
    {MAT_C_INT32, "MAT_C_INT32"},
    {MAT_C_UINT32, "MAT_C_UINT32"},
    {MAT_C_INT64, "MAT_C_INT64"},
    {MAT_C_UINT64, "MAT_C_UINT64"},
    {MAT_C_FUNCTION, "MAT_C_FUNCTION"},
};

std::map<matio_compression, std::string> compress_str = {
    {MAT_COMPRESSION_NONE, "MAT_COMPRESSION_NONE"},
    {MAT_COMPRESSION_ZLIB, "MAT_COMPRESSION_ZLIB"},
};

int main(int argc, char *argv[]) {
  const char *fileName = "../data/mnist_uint8.mat";
  mat_t *mat = Mat_Open(fileName, MAT_ACC_RDONLY);
  if (mat) {
    std::cout << "reading mat file..." << std::endl;
    matvar_t *var = 0;
    while((var = Mat_VarReadNextInfo(mat)) != NULL){
      std::cout<<"name : " << var->name<<std::endl;
        matvar_t *matVar = Mat_VarRead(mat, var->name);
        
        std::cout<<"\tnbytes: "<<matVar->nbytes<<std::endl;
        std::cout<<"\tdata_size: "<<matVar->data_size<<std::endl;
        std::cout<<"\tdata_type : "<<type_str[matVar->data_type]<<std::endl;
      std::cout<<"\trank : " << matVar->rank<<std::endl;
        std::cout<<"\tdims : " ;
        for (int i = 0 ; i < matVar->rank; ++i)
            std::cout << "\t" << matVar->dims[i];
        std::cout<<std::endl;
      std::cout<<"\tclass_type : " <<class_str[matVar->class_type]<<std::endl;
      std::cout<<"\tisComplex : " <<matVar->isComplex<<std::endl;
      std::cout<<"\tisLogical : "<<matVar->isLogical<<std::endl;
      std::cout<<"\tisGlobal : " <<matVar->isGlobal<<std::endl;
        std::cout<<"\tcompression : "<<compress_str[matVar->compression]<<std::endl;
    }
    std::cout << "closing mat file..." << std::endl;
    Mat_Close(mat);

  } else {
    std::cout << "Cannot open mat file..." << std::endl;
    return 1;
  }
  return 0;
}
