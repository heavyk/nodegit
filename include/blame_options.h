#ifndef GITBLAMEOPTIONS_H
#define GITBLAMEOPTIONS_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/oid.h"
 
using namespace node;
using namespace v8;

class GitBlameOptions : public Nan::ObjectWrap {
  public:
    GitBlameOptions(git_blame_options* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_blame_options *GetValue();
    git_blame_options **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

               
  private:
    GitBlameOptions();
    ~GitBlameOptions();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

  
        static NAN_GETTER(GetVersion);
        static NAN_SETTER(SetVersion);

   
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

   
        static NAN_GETTER(GetMinMatchCharacters);
        static NAN_SETTER(SetMinMatchCharacters);

             Nan::Persistent<Object> newest_commit;
  
        static NAN_GETTER(GetNewestCommit);
        static NAN_SETTER(SetNewestCommit);

             Nan::Persistent<Object> oldest_commit;
  
        static NAN_GETTER(GetOldestCommit);
        static NAN_SETTER(SetOldestCommit);

   
        static NAN_GETTER(GetMinLine);
        static NAN_SETTER(SetMinLine);

   
        static NAN_GETTER(GetMaxLine);
        static NAN_SETTER(SetMaxLine);

  
    git_blame_options *raw;
};

#endif
