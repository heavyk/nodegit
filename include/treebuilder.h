#ifndef GITTREEBUILDER_H
#define GITTREEBUILDER_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/tree_entry.h"
#include "../include/oid.h"
#include "../include/repository.h"
#include "../include/tree.h"
// Forward declaration.
struct git_treebuilder {
};

using namespace node;
using namespace v8;

class GitTreebuilder : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_treebuilder *GetValue();
    git_treebuilder **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                  

  private:


    GitTreebuilder(git_treebuilder *raw, bool selfFreeing);
    ~GitTreebuilder();
                                  
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Clear);

    static NAN_METHOD(Entrycount);

    static NAN_METHOD(Free);

    static NAN_METHOD(Get);

    struct InsertBaton {
      int error_code;
      const git_error* error;
      const git_tree_entry * out;
      git_treebuilder * bld;
      const char * filename;
      const git_oid * id;
      bool idNeedsFree;
      git_filemode_t filemode;
    };
    class InsertWorker : public Nan::AsyncWorker {
      public:
        InsertWorker(
            InsertBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~InsertWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        InsertBaton *baton;
    };

    static NAN_METHOD(Insert);

    struct CreateBaton {
      int error_code;
      const git_error* error;
      git_treebuilder * out;
      git_repository * repo;
      const git_tree * source;
    };
    class CreateWorker : public Nan::AsyncWorker {
      public:
        CreateWorker(
            CreateBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~CreateWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        CreateBaton *baton;
    };

    static NAN_METHOD(Create);

    static NAN_METHOD(Remove);

    static NAN_METHOD(Write);
    git_treebuilder *raw;
};

#endif
