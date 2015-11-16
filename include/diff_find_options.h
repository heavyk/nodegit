#ifndef GITDIFFFINDOPTIONS_H
#define GITDIFFFINDOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

 
using namespace node;
using namespace v8;

class GitDiffFindOptions : public Nan::ObjectWrap {
  public:
    GitDiffFindOptions(git_diff_find_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff_find_options *GetValue();
    git_diff_find_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

               
  private:
    GitDiffFindOptions();
    ~GitDiffFindOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

   
        static NAN_GETTER(GetRenameThreshold);
        static NAN_SETTER(SetRenameThreshold);

   
        static NAN_GETTER(GetRenameFromRewriteThreshold);
        static NAN_SETTER(SetRenameFromRewriteThreshold);

   
        static NAN_GETTER(GetCopyThreshold);
        static NAN_SETTER(SetCopyThreshold);

   
        static NAN_GETTER(GetBreakRewriteThreshold);
        static NAN_SETTER(SetBreakRewriteThreshold);

   
        static NAN_GETTER(GetRenameLimit);
        static NAN_SETTER(SetRenameLimit);

  
    git_diff_find_options *raw;
};

#endif
