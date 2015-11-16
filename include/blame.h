#ifndef GITBLAME_H
#define GITBLAME_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/repository.h"
#include "../include/blame_options.h"
#include "../include/blame_hunk.h"

using namespace node;
using namespace v8;

class GitBlame : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_blame *GetValue();
    git_blame **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                               

  private:


    GitBlame(git_blame *raw, bool selfFreeing);
    ~GitBlame();
                               
    static NAN_METHOD(JSNewFunction);


    struct BufferBaton {
      int error_code;
      const git_error* error;
      git_blame * out;
      git_blame * reference;
      const char * buffer;
      size_t buffer_len;
    };
    class BufferWorker : public Nan::AsyncWorker {
      public:
        BufferWorker(
            BufferBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~BufferWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        BufferBaton *baton;
    };

    static NAN_METHOD(Buffer);

    struct FileBaton {
      int error_code;
      const git_error* error;
      git_blame * out;
      git_repository * repo;
      const char * path;
      git_blame_options * options;
    };
    class FileWorker : public Nan::AsyncWorker {
      public:
        FileWorker(
            FileBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FileWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FileBaton *baton;
    };

    static NAN_METHOD(File);

    static NAN_METHOD(Free);

    static NAN_METHOD(GetHunkByindex);

    static NAN_METHOD(GetHunkByline);

    static NAN_METHOD(GetHunkCount);

    static NAN_METHOD(InitOptions);
    git_blame *raw;
};

#endif
