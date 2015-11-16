#ifndef GITTRANSPORT_H
#define GITTRANSPORT_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/transport.h>
}

#include "../include/remote.h"

using namespace node;
using namespace v8;

class GitTransport : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_transport *GetValue();
    git_transport **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

             

  private:


    GitTransport(git_transport *raw, bool selfFreeing);
    ~GitTransport();
             
    static NAN_METHOD(JSNewFunction);


    static NAN_METHOD(Init);

    struct SshWithPathsBaton {
      int error_code;
      const git_error* error;
      git_transport * out;
      git_remote * owner;
      void * payload;
    };
    class SshWithPathsWorker : public Nan::AsyncWorker {
      public:
        SshWithPathsWorker(
            SshWithPathsBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SshWithPathsWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SshWithPathsBaton *baton;
    };

    static NAN_METHOD(SshWithPaths);

    static NAN_METHOD(Unregister);

    struct SshWithPaths_globalPayload {

      SshWithPaths_globalPayload() {
      }

      ~SshWithPaths_globalPayload() {
      }
    };
    git_transport *raw;
};

#endif
