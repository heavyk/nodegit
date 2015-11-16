#ifndef GITCONFIG_H
#define GITCONFIG_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/git_buf_converter.h"
#include "../include/buf.h"
// Forward declaration.
struct git_config {
};

using namespace node;
using namespace v8;

class GitConfig : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_config *GetValue();
    git_config **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                             

  private:


    GitConfig(git_config *raw, bool selfFreeing);
    ~GitConfig();
                             
    static NAN_METHOD(JSNewFunction);


    struct GetStringBufBaton {
      int error_code;
      const git_error* error;
      git_buf * out;
      const git_config * cfg;
      const char * name;
    };
    class GetStringBufWorker : public Nan::AsyncWorker {
      public:
        GetStringBufWorker(
            GetStringBufBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetStringBufWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetStringBufBaton *baton;
    };

    static NAN_METHOD(GetStringBuf);

    struct OpenDefaultBaton {
      int error_code;
      const git_error* error;
      git_config * out;
    };
    class OpenDefaultWorker : public Nan::AsyncWorker {
      public:
        OpenDefaultWorker(
            OpenDefaultBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~OpenDefaultWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        OpenDefaultBaton *baton;
    };

    static NAN_METHOD(OpenDefault);

    static NAN_METHOD(SetInt64);

    static NAN_METHOD(SetMultivar);

    struct SetStringBaton {
      int error_code;
      const git_error* error;
      git_config * cfg;
      const char * name;
      const char * value;
    };
    class SetStringWorker : public Nan::AsyncWorker {
      public:
        SetStringWorker(
            SetStringBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SetStringWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SetStringBaton *baton;
    };

    static NAN_METHOD(SetString);

    struct SnapshotBaton {
      int error_code;
      const git_error* error;
      git_config * out;
      git_config * config;
    };
    class SnapshotWorker : public Nan::AsyncWorker {
      public:
        SnapshotWorker(
            SnapshotBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SnapshotWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SnapshotBaton *baton;
    };

    static NAN_METHOD(Snapshot);
    git_config *raw;
};

#endif
