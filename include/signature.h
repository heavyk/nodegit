#ifndef GITSIGNATURE_H
#define GITSIGNATURE_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/time.h"
#include "../include/repository.h"

using namespace node;
using namespace v8;

class GitSignature : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_signature *GetValue();
    git_signature **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                        

  private:


    GitSignature(git_signature *raw, bool selfFreeing);
    ~GitSignature();
                        
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Name);
    static NAN_METHOD(Email);
    static NAN_METHOD(When);

    static NAN_METHOD(Default);

    struct DupBaton {
      int error_code;
      const git_error* error;
      git_signature * dest;
      const git_signature * sig;
    };
    class DupWorker : public Nan::AsyncWorker {
      public:
        DupWorker(
            DupBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~DupWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        DupBaton *baton;
    };

    static NAN_METHOD(Dup);

    static NAN_METHOD(Free);

    static NAN_METHOD(Create);

    static NAN_METHOD(Now);
    git_signature *raw;
};

#endif
