#ifndef GITODBOBJECT_H
#define GITODBOBJECT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/wrapper.h"
#include "node_buffer.h"
#include "../include/oid.h"
// Forward declaration.
struct git_odb_object {
};

using namespace node;
using namespace v8;

class GitOdbObject : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_odb_object *GetValue();
    git_odb_object **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                    

  private:


    GitOdbObject(git_odb_object *raw, bool selfFreeing);
    ~GitOdbObject();
                    
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Data);

    struct DupBaton {
      int error_code;
      const git_error* error;
      git_odb_object * dest;
      git_odb_object * source;
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

    static NAN_METHOD(Id);

    static NAN_METHOD(Size);

    static NAN_METHOD(Type);
    git_odb_object *raw;
};

#endif
