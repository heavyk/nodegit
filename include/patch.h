#ifndef GITPATCH_H
#define GITPATCH_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
}

#include "../include/blob.h"
#include "../include/diff_options.h"
#include "../include/diff.h"
#include "../include/diff_delta.h"
#include "../include/diff_hunk.h"
#include "../include/diff_line.h"
// Forward declaration.
struct git_patch {
};

using namespace node;
using namespace v8;

class GitPatch : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_patch *GetValue();
    git_patch **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

                                                   

  private:


    GitPatch(git_patch *raw, bool selfFreeing);
    ~GitPatch();
                                                   
    static NAN_METHOD(JSNewFunction);


    struct FromBlobAndBufferBaton {
      int error_code;
      const git_error* error;
      git_patch * out;
      const git_blob * old_blob;
      const char * old_as_path;
      const char * buffer;
      size_t buffer_len;
      const char * buffer_as_path;
      const git_diff_options * opts;
    };
    class FromBlobAndBufferWorker : public Nan::AsyncWorker {
      public:
        FromBlobAndBufferWorker(
            FromBlobAndBufferBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromBlobAndBufferWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromBlobAndBufferBaton *baton;
    };

    static NAN_METHOD(FromBlobAndBuffer);

    struct FromBlobsBaton {
      int error_code;
      const git_error* error;
      git_patch * out;
      const git_blob * old_blob;
      const char * old_as_path;
      const git_blob * new_blob;
      const char * new_as_path;
      const git_diff_options * opts;
    };
    class FromBlobsWorker : public Nan::AsyncWorker {
      public:
        FromBlobsWorker(
            FromBlobsBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromBlobsWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromBlobsBaton *baton;
    };

    static NAN_METHOD(FromBlobs);

    struct FromDiffBaton {
      int error_code;
      const git_error* error;
      git_patch * out;
      git_diff * diff;
      size_t idx;
    };
    class FromDiffWorker : public Nan::AsyncWorker {
      public:
        FromDiffWorker(
            FromDiffBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FromDiffWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FromDiffBaton *baton;
    };

    static NAN_METHOD(FromDiff);

    static NAN_METHOD(GetDelta);

    struct GetHunkBaton {
      int error_code;
      const git_error* error;
      const git_diff_hunk * out;
      size_t * lines_in_hunk;
      git_patch * patch;
      size_t hunk_idx;
    };
    class GetHunkWorker : public Nan::AsyncWorker {
      public:
        GetHunkWorker(
            GetHunkBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetHunkWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetHunkBaton *baton;
    };

    static NAN_METHOD(GetHunk);

    struct GetLineInHunkBaton {
      int error_code;
      const git_error* error;
      const git_diff_line * out;
      git_patch * patch;
      size_t hunk_idx;
      size_t line_of_hunk;
    };
    class GetLineInHunkWorker : public Nan::AsyncWorker {
      public:
        GetLineInHunkWorker(
            GetLineInHunkBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetLineInHunkWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetLineInHunkBaton *baton;
    };

    static NAN_METHOD(GetLineInHunk);

    static NAN_METHOD(NumHunks);

    static NAN_METHOD(NumLinesInHunk);

    static NAN_METHOD(Size);
    git_patch *raw;
};

#endif
