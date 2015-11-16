#ifndef GITBUF_H
#define GITBUF_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/git_buf_converter.h"

using namespace node;
using namespace v8;

class GitBuf : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_buf *GetValue();
    git_buf **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                   

  private:


    GitBuf(git_buf *raw, bool selfFreeing);
    ~GitBuf();
                   
    static NAN_METHOD(JSNewFunction);

    static NAN_METHOD(Ptr);
    static NAN_METHOD(Asize);
    static NAN_METHOD(Size);

    static NAN_METHOD(ContainsNul);

    static NAN_METHOD(Free);

    struct GrowBaton {
      int error_code;
      const git_error* error;
      git_buf * buffer;
      size_t target_size;
    };
    class GrowWorker : public Nan::AsyncWorker {
      public:
        GrowWorker(
            GrowBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GrowWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GrowBaton *baton;
    };

    static NAN_METHOD(Grow);

    static NAN_METHOD(IsBinary);

    struct SetBaton {
      int error_code;
      const git_error* error;
      git_buf * buffer;
      const void * data;
      size_t datalen;
    };
    class SetWorker : public Nan::AsyncWorker {
      public:
        SetWorker(
            SetBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~SetWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        SetBaton *baton;
    };

    static NAN_METHOD(Set);
    git_buf *raw;
};

#endif
