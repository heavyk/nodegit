#ifndef GITDIFFBINARYFILE_H
#define GITDIFFBINARYFILE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitDiffBinaryFile : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_binary_file *GetValue();
    git_diff_binary_file **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitDiffBinaryFile(git_diff_binary_file *raw, bool selfFreeing);
    ~GitDiffBinaryFile();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Type);
    static NAN_METHOD(Data);
    static NAN_METHOD(Datalen);
    static NAN_METHOD(Inflatedlen);
    git_diff_binary_file *raw;
};

#endif
