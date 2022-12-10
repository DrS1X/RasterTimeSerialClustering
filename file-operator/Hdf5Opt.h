//
// Created by Administrator on 2022/12/4.
//

#ifndef CLUSTERING_HDF5OPT_H
#define CLUSTERING_HDF5OPT_H

// H5api_adpt.h
#ifndef H5_BUILT_AS_DYNAMIC_LIB
#define H5_BUILT_AS_DYNAMIC_LIB
#endif

#include <string>
#include <assert.h>
#include <unordered_map>
#include <hdf5.h>
#include <H5Cpp.h>

#include "FileOperator.h"
#include "DataModel.h"
#include "_const.h"

using std::string;

class Hdf5Opt : public FileOperator{
public:
    string groupName, datasetName;
    H5::DataType dataType;

    Hdf5Opt(string _groupName, string _datasetName);
    void getMeta(string fileName, Meta& meta);

    static std::unordered_map<string, string> parseAttribute(char* attText);

    bool read(RFile file);
};

#endif //CLUSTERING_HDF5OPT_H