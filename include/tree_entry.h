#ifndef GITTREEENTRY_H
#define GITTREEENTRY_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/oid.h"
// Forward declaration.
struct git_tree_entry {
      uint16_t attr;
      git_oid oid;
      size_t filename_len;
      char filename[1];
};

using namespace node;
using namespace v8;

class GitTreeEntry : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_tree_entry *GetValue();
    git_tree_entry **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

 

  private:


    GitTreeEntry(git_tree_entry *raw, bool selfFreeing);
    ~GitTreeEntry();
 
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Attr);
    static NAN_METHOD(Oid);
    static NAN_METHOD(FilenameLen);
    static NAN_METHOD(Filename);
    git_tree_entry *raw;
};

#endif
