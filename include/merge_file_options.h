#ifndef GITMERGEFILEOPTIONS_H
#define GITMERGEFILEOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

 
using namespace node;
using namespace v8;

class GitMergeFileOptions : public Nan::ObjectWrap {
  public:
    GitMergeFileOptions(git_merge_file_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_merge_file_options *GetValue();
    git_merge_file_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

             
  private:
    GitMergeFileOptions();
    ~GitMergeFileOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetAncestorLabel);
        static NAN_SETTER(SetAncestorLabel);

   
        static NAN_GETTER(GetOurLabel);
        static NAN_SETTER(SetOurLabel);

   
        static NAN_GETTER(GetTheirLabel);
        static NAN_SETTER(SetTheirLabel);

  
        static NAN_GETTER(GetFavor);
        static NAN_SETTER(SetFavor);

   
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

  
    git_merge_file_options *raw;
};

#endif
