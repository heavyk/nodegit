#ifndef GITINDEXENTRY_H
#define GITINDEXENTRY_H
// generated from struct_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
  #include <git2.h>
 }

  #include "../include/index_time.h"
  #include "../include/oid.h"
 
using namespace node;
using namespace v8;

class GitIndexEntry : public Nan::ObjectWrap {
  public:
    GitIndexEntry(git_index_entry* raw, bool selfFreeing);
    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_index_entry *GetValue();
    git_index_entry **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);

    bool selfFreeing;

                         
  private:
    GitIndexEntry();
    ~GitIndexEntry();

    void ConstructFields();

    static NAN_METHOD(JSNewFunction);

            Nan::Persistent<Object> ctime;
  
        static NAN_GETTER(GetCtime);
        static NAN_SETTER(SetCtime);

             Nan::Persistent<Object> mtime;
  
        static NAN_GETTER(GetMtime);
        static NAN_SETTER(SetMtime);

   
        static NAN_GETTER(GetDev);
        static NAN_SETTER(SetDev);

   
        static NAN_GETTER(GetIno);
        static NAN_SETTER(SetIno);

   
        static NAN_GETTER(GetMode);
        static NAN_SETTER(SetMode);

   
        static NAN_GETTER(GetUid);
        static NAN_SETTER(SetUid);

   
        static NAN_GETTER(GetGid);
        static NAN_SETTER(SetGid);

   
        static NAN_GETTER(GetFileSize);
        static NAN_SETTER(SetFileSize);

             Nan::Persistent<Object> id;
  
        static NAN_GETTER(GetId);
        static NAN_SETTER(SetId);

   
        static NAN_GETTER(GetFlags);
        static NAN_SETTER(SetFlags);

   
        static NAN_GETTER(GetFlagsExtended);
        static NAN_SETTER(SetFlagsExtended);

   
        static NAN_GETTER(GetPath);
        static NAN_SETTER(SetPath);

  
    git_index_entry *raw;
};

#endif
