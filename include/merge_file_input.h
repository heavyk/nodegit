#ifndef GITMERGEFILEINPUT_H
#define GITMERGEFILEINPUT_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

 
using namespace node;
using namespace v8;

class GitMergeFileInput : public Nan::ObjectWrap {
  public:
    GitMergeFileInput(git_merge_file_input* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_merge_file_input *GetValue();
    git_merge_file_input **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

           
  private:
    GitMergeFileInput();
    ~GitMergeFileInput();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetPtr);
        static NAN_SETTER(SetPtr);

   
        static NAN_GETTER(GetSize);
        static NAN_SETTER(SetSize);

   
        static NAN_GETTER(GetPath);
        static NAN_SETTER(SetPath);

   
        static NAN_GETTER(GetMode);
        static NAN_SETTER(SetMode);

  
    git_merge_file_input *raw;
};

#endif
