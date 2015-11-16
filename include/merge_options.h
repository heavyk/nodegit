#ifndef GITMERGEOPTIONS_H
#define GITMERGEOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

 
using namespace node;
using namespace v8;

class GitMergeOptions : public Nan::ObjectWrap {
  public:
    GitMergeOptions(git_merge_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_merge_options *GetValue();
    git_merge_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

             
  private:
    GitMergeOptions();
    ~GitMergeOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

  
        static NAN_GETTER(GetTreeFlags);
        static NAN_SETTER(SetTreeFlags);

   
        static NAN_GETTER(GetRenameThreshold);
        static NAN_SETTER(SetRenameThreshold);

   
        static NAN_GETTER(GetTargetLimit);
        static NAN_SETTER(SetTargetLimit);

  
        static NAN_GETTER(GetFileFavor);
        static NAN_SETTER(SetFileFavor);

   
        static NAN_GETTER(GetFileFlags);
        static NAN_SETTER(SetFileFlags);

  
    git_merge_options *raw;
};

#endif
