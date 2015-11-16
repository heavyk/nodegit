#ifndef GITMERGEFILERESULT_H
#define GITMERGEFILERESULT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}


using namespace node;
using namespace v8;

class GitMergeFileResult : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_merge_file_result *GetValue();
    git_merge_file_result **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitMergeFileResult(git_merge_file_result *raw, bool selfFreeing);
    ~GitMergeFileResult();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Automergeable);
    static NAN_METHOD(Path);
    static NAN_METHOD(Mode);
    static NAN_METHOD(Ptr);
    static NAN_METHOD(Len);
    git_merge_file_result *raw;
};

#endif
