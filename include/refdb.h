#ifndef GITREFDB_H
#define GITREFDB_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
// Forward declaration.
struct git_refdb {
};

using namespace node;
using namespace v8;

class GitRefdb : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_refdb *GetValue();
    git_refdb **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

           

  private:


    GitRefdb(git_refdb *raw, bool selfFreeing);
    ~GitRefdb();
           
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Compress);

    static NAN_METHOD(Free);

    struct OpenBaton {
      int error_code;
      const git_error* error;
      git_refdb * out;
      git_repository * repo;
    };
    class OpenWorker : public Nan::AsyncWorker {
      public:
        OpenWorker(
            OpenBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenBaton *baton;
    };

    static NAN_METHOD(Open);
    git_refdb *raw;
};

#endif
