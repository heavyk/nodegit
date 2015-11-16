#ifndef GITATTR_H
#define GITATTR_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"

using namespace node;
using namespace v8;

class GitAttr : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    bool selfFreeing;

                           

  private:


                           
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(AddMacro);

    static NAN_METHOD(CacheFlush);

    struct GetBaton {
      int error_code;
      const git_error* error;
      const char * value_out;
      git_repository * repo;
      uint32_t flags;
      const char * path;
      const char * name;
    };
    class GetWorker : public Nan::AsyncWorker {
      public:
        GetWorker(
            GetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetBaton *baton;
    };

    static NAN_METHOD(Get);

    static NAN_METHOD(GetMany);

    static NAN_METHOD(Value);
};

#endif
