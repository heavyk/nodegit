#ifndef GITDIFF_H
#define GITDIFF_H
// generated from class_header.h
#include <nan.h>
#include <string>
#include <queue>

extern "C" {
#include <git2.h>
#include <git2/sys/diff.h>
}

#include "../include/blob.h"
#include "../include/diff_options.h"
#include "../include/diff_delta.h"
#include "../include/diff_binary.h"
#include "../include/diff_hunk.h"
#include "../include/diff_line.h"
#include "../include/diff_find_options.h"
#include "../include/diff_perfdata.h"
#include "../include/repository.h"
#include "../include/index.h"
#include "../include/tree.h"
// Forward declaration.
struct git_diff {
};

using namespace node;
using namespace v8;

class GitDiff : public Nan::ObjectWrap {
  public:

    static Nan::Persistent<Function> constructor_template;
    static void InitializeComponent (Local<v8::Object> target);

    git_diff *GetValue();
    git_diff **GetRefValue();
    void ClearValue();

    static Local<v8::Value> New(void *raw, bool selfFreeing);
    bool selfFreeing;

          static int BlobToBuffer_file_cb_cppCallback (
      const git_diff_delta * delta
      ,
       float progress
      ,
       void * payload
      );

    static void BlobToBuffer_file_cb_async(uv_async_t* req, int status);
    static void BlobToBuffer_file_cb_setupAsyncPromisePolling(uv_async_t* req);
    static void BlobToBuffer_file_cb_asyncPromisePolling(uv_async_t* req, int status);
    struct BlobToBuffer_FileCbBaton {
      const git_diff_delta * delta;
      float progress;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
     static int BlobToBuffer_binary_cb_cppCallback (
      const git_diff_delta * delta
      ,
       const git_diff_binary * binary
      ,
       void * payload
      );

    static void BlobToBuffer_binary_cb_async(uv_async_t* req, int status);
    static void BlobToBuffer_binary_cb_setupAsyncPromisePolling(uv_async_t* req);
    static void BlobToBuffer_binary_cb_asyncPromisePolling(uv_async_t* req, int status);
    struct BlobToBuffer_BinaryCbBaton {
      const git_diff_delta * delta;
      const git_diff_binary * binary;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
     static int BlobToBuffer_hunk_cb_cppCallback (
      const git_diff_delta * delta
      ,
       const git_diff_hunk * hunk
      ,
       void * payload
      );

    static void BlobToBuffer_hunk_cb_async(uv_async_t* req, int status);
    static void BlobToBuffer_hunk_cb_setupAsyncPromisePolling(uv_async_t* req);
    static void BlobToBuffer_hunk_cb_asyncPromisePolling(uv_async_t* req, int status);
    struct BlobToBuffer_HunkCbBaton {
      const git_diff_delta * delta;
      const git_diff_hunk * hunk;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
     static int BlobToBuffer_line_cb_cppCallback (
      const git_diff_delta * delta
      ,
       const git_diff_hunk * hunk
      ,
       const git_diff_line * line
      ,
       void * payload
      );

    static void BlobToBuffer_line_cb_async(uv_async_t* req, int status);
    static void BlobToBuffer_line_cb_setupAsyncPromisePolling(uv_async_t* req);
    static void BlobToBuffer_line_cb_asyncPromisePolling(uv_async_t* req, int status);
    struct BlobToBuffer_LineCbBaton {
      const git_diff_delta * delta;
      const git_diff_hunk * hunk;
      const git_diff_line * line;
      void * payload;
 
      uv_async_t req;
      int result;
      Nan::Persistent<Object> promise;
      bool done;
    };
                                                    

  private:


    GitDiff(git_diff *raw, bool selfFreeing);
    ~GitDiff();
                                                             
    static NAN_METHOD(JSNewFunction);


    struct BlobToBufferBaton {
      int error_code;
      const git_error* error;
      const git_blob * old_blob;
      const char * old_as_path;
      const char * buffer;
      size_t buffer_len;
      const char * buffer_as_path;
      const git_diff_options * options;
      git_diff_file_cb file_cb;
      git_diff_binary_cb binary_cb;
      git_diff_hunk_cb hunk_cb;
      git_diff_line_cb line_cb;
      void * payload;
    };
    class BlobToBufferWorker : public Nan::AsyncWorker {
      public:
        BlobToBufferWorker(
            BlobToBufferBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~BlobToBufferWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        BlobToBufferBaton *baton;
    };

    static NAN_METHOD(BlobToBuffer);

    struct FindSimilarBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      const git_diff_find_options * options;
    };
    class FindSimilarWorker : public Nan::AsyncWorker {
      public:
        FindSimilarWorker(
            FindSimilarBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~FindSimilarWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        FindSimilarBaton *baton;
    };

    static NAN_METHOD(FindSimilar);

    static NAN_METHOD(GetDelta);

    struct GetPerfdataBaton {
      int error_code;
      const git_error* error;
      git_diff_perfdata * out;
      const git_diff * diff;
    };
    class GetPerfdataWorker : public Nan::AsyncWorker {
      public:
        GetPerfdataWorker(
            GetPerfdataBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~GetPerfdataWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        GetPerfdataBaton *baton;
    };

    static NAN_METHOD(GetPerfdata);

    struct IndexToWorkdirBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_index * index;
      const git_diff_options * opts;
    };
    class IndexToWorkdirWorker : public Nan::AsyncWorker {
      public:
        IndexToWorkdirWorker(
            IndexToWorkdirBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~IndexToWorkdirWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        IndexToWorkdirBaton *baton;
    };

    static NAN_METHOD(IndexToWorkdir);

    static NAN_METHOD(NumDeltas);

    struct TreeToIndexBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      git_index * index;
      const git_diff_options * opts;
    };
    class TreeToIndexWorker : public Nan::AsyncWorker {
      public:
        TreeToIndexWorker(
            TreeToIndexBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~TreeToIndexWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        TreeToIndexBaton *baton;
    };

    static NAN_METHOD(TreeToIndex);

    struct TreeToTreeBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      git_tree * new_tree;
      const git_diff_options * opts;
    };
    class TreeToTreeWorker : public Nan::AsyncWorker {
      public:
        TreeToTreeWorker(
            TreeToTreeBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~TreeToTreeWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        TreeToTreeBaton *baton;
    };

    static NAN_METHOD(TreeToTree);

    struct TreeToWorkdirBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      const git_diff_options * opts;
    };
    class TreeToWorkdirWorker : public Nan::AsyncWorker {
      public:
        TreeToWorkdirWorker(
            TreeToWorkdirBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~TreeToWorkdirWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        TreeToWorkdirBaton *baton;
    };

    static NAN_METHOD(TreeToWorkdir);

    struct TreeToWorkdirWithIndexBaton {
      int error_code;
      const git_error* error;
      git_diff * diff;
      git_repository * repo;
      git_tree * old_tree;
      const git_diff_options * opts;
    };
    class TreeToWorkdirWithIndexWorker : public Nan::AsyncWorker {
      public:
        TreeToWorkdirWithIndexWorker(
            TreeToWorkdirWithIndexBaton *_baton,
            Nan::Callback *callback
        ) : Nan::AsyncWorker(callback)
          , baton(_baton) {};
        ~TreeToWorkdirWithIndexWorker() {};
        void Execute();
        void HandleOKCallback();

      private:
        TreeToWorkdirWithIndexBaton *baton;
    };

    static NAN_METHOD(TreeToWorkdirWithIndex);

    struct BlobToBuffer_globalPayload {
      Nan::Callback * file_cb;
      Nan::Callback * binary_cb;
      Nan::Callback * hunk_cb;
      Nan::Callback * line_cb;

      BlobToBuffer_globalPayload() {
        file_cb = NULL;
        binary_cb = NULL;
        hunk_cb = NULL;
        line_cb = NULL;
      }

      ~BlobToBuffer_globalPayload() {
        if (file_cb != NULL) {
          delete file_cb;
        }
        if (binary_cb != NULL) {
          delete binary_cb;
        }
        if (hunk_cb != NULL) {
          delete hunk_cb;
        }
        if (line_cb != NULL) {
          delete line_cb;
        }
      }
    };
    git_diff *raw;
};

#endif
