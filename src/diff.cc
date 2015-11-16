// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/diff.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff.h"
#include "../include/functions/sleep_for_ms.h"

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
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiff::GitDiff(git_diff *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiff::~GitDiff() {
      if (this->selfFreeing) {
        git_diff_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                               }

  void GitDiff::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Diff").ToLocalChecked());

           Nan::SetMethod(tpl, "blobToBuffer", BlobToBuffer);
            Nan::SetPrototypeMethod(tpl, "findSimilar", FindSimilar);
            Nan::SetPrototypeMethod(tpl, "getDelta", GetDelta);
            Nan::SetPrototypeMethod(tpl, "getPerfdata", GetPerfdata);
             Nan::SetMethod(tpl, "indexToWorkdir", IndexToWorkdir);
            Nan::SetPrototypeMethod(tpl, "numDeltas", NumDeltas);
             Nan::SetMethod(tpl, "treeToIndex", TreeToIndex);
             Nan::SetMethod(tpl, "treeToTree", TreeToTree);
             Nan::SetMethod(tpl, "treeToWorkdir", TreeToWorkdir);
             Nan::SetMethod(tpl, "treeToWorkdirWithIndex", TreeToWorkdirWithIndex);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Diff").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiff::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiff cannot be instantiated.");
     }

    GitDiff* object = new GitDiff(static_cast<git_diff *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiff::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiff::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff *GitDiff::GetValue() {
    return this->raw;
  }

  git_diff **GitDiff::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiff::ClearValue() {
    this->raw = NULL;
  }

 
/*
 * @param Blob old_blob
   * @param String old_as_path
   * @param String buffer
   * @param Number buffer_len
   * @param String buffer_as_path
   * @param DiffOptions options
   * @param DiffFileCb file_cb
   * @param DiffBinaryCb binary_cb
   * @param DiffHunkCb hunk_cb
   * @param DiffLineCb line_cb
   * @param Void payload
     */
NAN_METHOD(GitDiff::BlobToBuffer) {

  if (info.Length() == 11 || !info[11]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  BlobToBufferBaton* baton = new BlobToBufferBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  BlobToBuffer_globalPayload* globalPayload = new BlobToBuffer_globalPayload;
// start convert_from_v8 block
  const git_blob * from_old_blob;
    if (info[0]->IsObject()) {
  from_old_blob = Nan::ObjectWrap::Unwrap<GitBlob>(info[0]->ToObject())->GetValue();
  }
  else {
    from_old_blob = 0;
  }
// end convert_from_v8 block
  baton->old_blob = from_old_blob;
// start convert_from_v8 block
  const char * from_old_as_path;
    if (info[1]->IsString()) {

  String::Utf8Value old_as_path(info[1]->ToString());
  from_old_as_path = (const char *) strdup(*old_as_path);
  }
  else {
    from_old_as_path = 0;
  }
// end convert_from_v8 block
  baton->old_as_path = from_old_as_path;
// start convert_from_v8 block
  const char * from_buffer;
    if (info[2]->IsString()) {

  String::Utf8Value buffer(info[2]->ToString());
  from_buffer = (const char *) strdup(*buffer);
  }
  else {
    from_buffer = 0;
  }
// end convert_from_v8 block
  baton->buffer = from_buffer;
// start convert_from_v8 block
  size_t from_buffer_len;
    if (info[3]->IsNumber()) {
  from_buffer_len = (size_t)   info[3]->ToNumber()->Value();
  }
  else {
    from_buffer_len = 0;
  }
// end convert_from_v8 block
  baton->buffer_len = from_buffer_len;
// start convert_from_v8 block
  const char * from_buffer_as_path;
    if (info[4]->IsString()) {

  String::Utf8Value buffer_as_path(info[4]->ToString());
  from_buffer_as_path = (const char *) strdup(*buffer_as_path);
  }
  else {
    from_buffer_as_path = 0;
  }
// end convert_from_v8 block
  baton->buffer_as_path = from_buffer_as_path;
// start convert_from_v8 block
  const git_diff_options * from_options;
    if (info[5]->IsObject()) {
  from_options = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[5]->ToObject())->GetValue();
  }
  else {
    from_options = 0;
  }
// end convert_from_v8 block
  baton->options = from_options;
  if (!info[6]->IsFunction()) {
    baton->file_cb = NULL;
    globalPayload->file_cb = NULL;
  }
  else {
    baton->file_cb = BlobToBuffer_file_cb_cppCallback;
    globalPayload->file_cb = new Nan::Callback(info[6].As<Function>());
  }
  if (!info[7]->IsFunction()) {
    baton->binary_cb = NULL;
    globalPayload->binary_cb = NULL;
  }
  else {
    baton->binary_cb = BlobToBuffer_binary_cb_cppCallback;
    globalPayload->binary_cb = new Nan::Callback(info[7].As<Function>());
  }
  if (!info[8]->IsFunction()) {
    baton->hunk_cb = NULL;
    globalPayload->hunk_cb = NULL;
  }
  else {
    baton->hunk_cb = BlobToBuffer_hunk_cb_cppCallback;
    globalPayload->hunk_cb = new Nan::Callback(info[8].As<Function>());
  }
  if (!info[9]->IsFunction()) {
    baton->line_cb = NULL;
    globalPayload->line_cb = NULL;
  }
  else {
    baton->line_cb = BlobToBuffer_line_cb_cppCallback;
    globalPayload->line_cb = new Nan::Callback(info[9].As<Function>());
  }
  baton->payload = globalPayload;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[11]));
  BlobToBufferWorker *worker = new BlobToBufferWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("old_blob", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_as_path", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("buffer", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("buffer_len", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("buffer_as_path", info[4]->ToObject());
  if (!info[5]->IsUndefined() && !info[5]->IsNull())
    worker->SaveToPersistent("options", info[5]->ToObject());
  if (!info[10]->IsUndefined() && !info[10]->IsNull())
    worker->SaveToPersistent("payload", info[10]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::BlobToBufferWorker::Execute() {
  int result = git_diff_blob_to_buffer(
baton->old_blob,baton->old_as_path,baton->buffer,baton->buffer_len,baton->buffer_as_path,baton->options,baton->file_cb,baton->binary_cb,baton->hunk_cb,baton->line_cb,baton->payload    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::BlobToBufferWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> result = Nan::Undefined();
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("old_blob"));
      workerArguments.push(GetFromPersistent("old_as_path"));
      workerArguments.push(GetFromPersistent("buffer"));
      workerArguments.push(GetFromPersistent("buffer_len"));
      workerArguments.push(GetFromPersistent("buffer_as_path"));
      workerArguments.push(GetFromPersistent("options"));
      workerArguments.push(GetFromPersistent("payload"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method blobToBuffer has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  free((void *)baton->old_as_path);
  free((void *)baton->buffer);
  free((void *)baton->buffer_as_path);
  delete (BlobToBuffer_globalPayload*)baton->payload;

  delete baton;
}


int GitDiff::BlobToBuffer_file_cb_cppCallback (
    const git_diff_delta * delta,     float progress,     void * payload  ) {
  BlobToBuffer_FileCbBaton* baton = new BlobToBuffer_FileCbBaton();

    baton->delta = delta;
    baton->progress = progress;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_file_cb_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitDiff::BlobToBuffer_file_cb_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_FileCbBaton* baton = static_cast<BlobToBuffer_FileCbBaton*>(req->data);

    Nan::Callback* callback = ((BlobToBuffer_globalPayload*)baton->payload)->file_cb;
   
  Local<Value> argv[3] = {
          GitDiffDelta::New((void *)baton->delta, false),
             Nan::New(baton->progress),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(3, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) BlobToBuffer_file_cb_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 1;
      }
     }
    else {
      baton->result = 1;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitDiff::BlobToBuffer_file_cb_setupAsyncPromisePolling(uv_async_t* req) {
  BlobToBuffer_FileCbBaton* baton = static_cast<BlobToBuffer_FileCbBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_file_cb_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitDiff::BlobToBuffer_file_cb_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_FileCbBaton* baton = static_cast<BlobToBuffer_FileCbBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 1;
        }
       }
      else {
        baton->result = 1;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->  payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}

int GitDiff::BlobToBuffer_binary_cb_cppCallback (
    const git_diff_delta * delta,     const git_diff_binary * binary,     void * payload  ) {
  BlobToBuffer_BinaryCbBaton* baton = new BlobToBuffer_BinaryCbBaton();

    baton->delta = delta;
    baton->binary = binary;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_binary_cb_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitDiff::BlobToBuffer_binary_cb_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_BinaryCbBaton* baton = static_cast<BlobToBuffer_BinaryCbBaton*>(req->data);

    Nan::Callback* callback = ((BlobToBuffer_globalPayload*)baton->payload)->binary_cb;
   
  Local<Value> argv[3] = {
          GitDiffDelta::New((void *)baton->delta, false),
            GitDiffBinary::New((void *)baton->binary, false),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(3, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) BlobToBuffer_binary_cb_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 0;
      }
     }
    else {
      baton->result = 0;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitDiff::BlobToBuffer_binary_cb_setupAsyncPromisePolling(uv_async_t* req) {
  BlobToBuffer_BinaryCbBaton* baton = static_cast<BlobToBuffer_BinaryCbBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_binary_cb_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitDiff::BlobToBuffer_binary_cb_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_BinaryCbBaton* baton = static_cast<BlobToBuffer_BinaryCbBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 0;
        }
       }
      else {
        baton->result = 0;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->  payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}

int GitDiff::BlobToBuffer_hunk_cb_cppCallback (
    const git_diff_delta * delta,     const git_diff_hunk * hunk,     void * payload  ) {
  BlobToBuffer_HunkCbBaton* baton = new BlobToBuffer_HunkCbBaton();

    baton->delta = delta;
    baton->hunk = hunk;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_hunk_cb_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitDiff::BlobToBuffer_hunk_cb_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_HunkCbBaton* baton = static_cast<BlobToBuffer_HunkCbBaton*>(req->data);

    Nan::Callback* callback = ((BlobToBuffer_globalPayload*)baton->payload)->hunk_cb;
   
  Local<Value> argv[3] = {
          GitDiffDelta::New((void *)baton->delta, false),
            GitDiffHunk::New((void *)baton->hunk, false),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(3, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) BlobToBuffer_hunk_cb_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 1;
      }
     }
    else {
      baton->result = 1;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitDiff::BlobToBuffer_hunk_cb_setupAsyncPromisePolling(uv_async_t* req) {
  BlobToBuffer_HunkCbBaton* baton = static_cast<BlobToBuffer_HunkCbBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_hunk_cb_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitDiff::BlobToBuffer_hunk_cb_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_HunkCbBaton* baton = static_cast<BlobToBuffer_HunkCbBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 1;
        }
       }
      else {
        baton->result = 1;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->  payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}

int GitDiff::BlobToBuffer_line_cb_cppCallback (
    const git_diff_delta * delta,     const git_diff_hunk * hunk,     const git_diff_line * line,     void * payload  ) {
  BlobToBuffer_LineCbBaton* baton = new BlobToBuffer_LineCbBaton();

    baton->delta = delta;
    baton->hunk = hunk;
    baton->line = line;
    baton->payload = payload;
 
  baton->result = 0;
  baton->req.data = baton;
  baton->done = false;

  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_line_cb_async);
  uv_async_send(&baton->req);

  while(!baton->done) {
    sleep_for_ms(1);
  }

  
  return baton->result;
}

void GitDiff::BlobToBuffer_line_cb_async(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_LineCbBaton* baton = static_cast<BlobToBuffer_LineCbBaton*>(req->data);

     Nan::Callback* callback = ((BlobToBuffer_globalPayload*)baton->payload)->line_cb;
   
  Local<Value> argv[4] = {
          GitDiffDelta::New((void *)baton->delta, false),
            GitDiffHunk::New((void *)baton->hunk, false),
            GitDiffLine::New((void *)baton->line, false),
          // payload is null because we can use closure scope in javascript
        Nan::Undefined()
    };

  Nan::TryCatch tryCatch;
  Local<v8::Value> result = callback->Call(4, argv);

  if (result->IsObject() && Nan::Has(result->ToObject(), Nan::New("then").ToLocalChecked()).FromJust()) {
    Local<v8::Value> thenProp = Nan::Get(result->ToObject(), Nan::New("then").ToLocalChecked()).ToLocalChecked();

    if (thenProp->IsFunction()) {
      // we can be reasonbly certain that the result is a promise
      Local<Object> promise = result->ToObject();

      baton->promise.Reset(promise);

      uv_close((uv_handle_t*) &baton->req, (uv_close_cb) BlobToBuffer_line_cb_setupAsyncPromisePolling);
      return;
    }
  }

    if (result.IsEmpty() || result->IsNativeError()) {
      baton->result = -1;
    }
    else if (!result->IsNull() && !result->IsUndefined()) {
       if (result->IsNumber()) {
        baton->result = (int)result->ToNumber()->Value();
      }
      else {
        baton->result = 1;
      }
     }
    else {
      baton->result = 1;
    }
 
  baton->done = true;
  uv_close((uv_handle_t*) &baton->req, NULL);
}

void GitDiff::BlobToBuffer_line_cb_setupAsyncPromisePolling(uv_async_t* req) {
  BlobToBuffer_LineCbBaton* baton = static_cast<BlobToBuffer_LineCbBaton*>(req->data);
  uv_async_init(uv_default_loop(), &baton->req, (uv_async_cb) BlobToBuffer_line_cb_asyncPromisePolling);
  uv_async_send(&baton->req);
}

void GitDiff::BlobToBuffer_line_cb_asyncPromisePolling(uv_async_t* req, int status) {
  Nan::HandleScope scope;

  BlobToBuffer_LineCbBaton* baton = static_cast<BlobToBuffer_LineCbBaton*>(req->data);
  Local<Object> promise = Nan::New<Object>(baton->promise);
  Nan::Callback* isPendingFn = new Nan::Callback(Nan::Get(promise, Nan::New("isPending").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Value> argv[1]; // MSBUILD won't assign an array of length 0
  Local<Boolean> isPending = isPendingFn->Call(promise, 0, argv)->ToBoolean();

  if (isPending->Value()) {
    uv_async_send(&baton->req);
    return;
  }

  Nan::Callback* isFulfilledFn = new Nan::Callback(Nan::Get(promise, Nan::New("isFulfilled").ToLocalChecked()).ToLocalChecked().As<Function>());
  Local<Boolean> isFulfilled = isFulfilledFn->Call(promise, 0, argv)->ToBoolean();

  if (isFulfilled->Value()) {
    Nan::Callback* resultFn = new Nan::Callback(Nan::Get(promise, Nan::New("value").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> result = resultFn->Call(promise, 0, argv);

      if (result.IsEmpty() || result->IsNativeError()) {
        baton->result = -1;
      }
      else if (!result->IsNull() && !result->IsUndefined()) {
         if (result->IsNumber()) {
          baton->result = (int)result->ToNumber()->Value();
        }
        else {
          baton->result = 1;
        }
       }
      else {
        baton->result = 1;
      }
     baton->done = true;
  }
  else {
    // promise was rejected
    GitDiff* instance = static_cast<GitDiff*>(baton->   payload  );
    Local<v8::Object> parent = instance->handle();
    Nan::Callback* reasonFn = new Nan::Callback(Nan::Get(promise, Nan::New("reason").ToLocalChecked()).ToLocalChecked().As<Function>());
    Local<v8::Value> reason = reasonFn->Call(promise, 0, argv);
    parent->SetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked(), reason);

    baton->result = -1;
    baton->done = true;
  }

  uv_close((uv_handle_t*) &baton->req, NULL);
}
  
/*
   * @param DiffFindOptions options
     */
NAN_METHOD(GitDiff::FindSimilar) {

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FindSimilarBaton* baton = new FindSimilarBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->diff = Nan::ObjectWrap::Unwrap<GitDiff>(info.This())->GetValue();
// start convert_from_v8 block
  const git_diff_find_options * from_options;
    if (info[0]->IsObject()) {
  from_options = Nan::ObjectWrap::Unwrap<GitDiffFindOptions>(info[0]->ToObject())->GetValue();
  }
  else {
    from_options = 0;
  }
// end convert_from_v8 block
  baton->options = from_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  FindSimilarWorker *worker = new FindSimilarWorker(baton, callback);
  worker->SaveToPersistent("diff", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("options", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::FindSimilarWorker::Execute() {
  int result = git_diff_find_similar(
baton->diff,baton->options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::FindSimilarWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> result = Nan::Undefined();
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("options"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method findSimilar has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
   * @param Number idx
     * @return DiffDelta  result    */
NAN_METHOD(GitDiff::GetDelta) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_diff_delta * result = git_diff_get_delta(
Nan::ObjectWrap::Unwrap<GitDiff>(info.This())->GetValue()
,from_idx
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitDiffDelta result
       to = GitDiffDelta::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param DiffPerfdata callback
   */
NAN_METHOD(GitDiff::GetPerfdata) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetPerfdataBaton* baton = new GetPerfdataBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->diff = Nan::ObjectWrap::Unwrap<GitDiff>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  GetPerfdataWorker *worker = new GetPerfdataWorker(baton, callback);
  worker->SaveToPersistent("diff", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::GetPerfdataWorker::Execute() {
  int result = git_diff_get_perfdata(
baton->out,baton->diff    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::GetPerfdataWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitDiffPerfdata baton->out
       to = GitDiffPerfdata::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method getPerfdata has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Index index
   * @param DiffOptions opts
    * @param Diff callback
   */
NAN_METHOD(GitDiff::IndexToWorkdir) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  IndexToWorkdirBaton* baton = new IndexToWorkdirBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_index * from_index;
    if (info[1]->IsObject()) {
  from_index = Nan::ObjectWrap::Unwrap<GitIndex>(info[1]->ToObject())->GetValue();
  }
  else {
    from_index = 0;
  }
// end convert_from_v8 block
  baton->index = from_index;
// start convert_from_v8 block
  const git_diff_options * from_opts;
    if (info[2]->IsObject()) {
  from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[2]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  IndexToWorkdirWorker *worker = new IndexToWorkdirWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("index", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("opts", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::IndexToWorkdirWorker::Execute() {
  int result = git_diff_index_to_workdir(
&baton->diff,baton->repo,baton->index,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::IndexToWorkdirWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->diff != NULL) {
    // GitDiff baton->diff
       to = GitDiff::New((void *)baton->diff, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("index"));
      workerArguments.push(GetFromPersistent("opts"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method indexToWorkdir has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
     * @return Number  result    */
NAN_METHOD(GitDiff::NumDeltas) {
  Nan::EscapableHandleScope scope;

   size_t result = git_diff_num_deltas(
Nan::ObjectWrap::Unwrap<GitDiff>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param Index index
   * @param DiffOptions opts
    * @param Diff callback
   */
NAN_METHOD(GitDiff::TreeToIndex) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  TreeToIndexBaton* baton = new TreeToIndexBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree;
    if (info[1]->IsObject()) {
  from_old_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[1]->ToObject())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
  baton->old_tree = from_old_tree;
// start convert_from_v8 block
  git_index * from_index;
    if (info[2]->IsObject()) {
  from_index = Nan::ObjectWrap::Unwrap<GitIndex>(info[2]->ToObject())->GetValue();
  }
  else {
    from_index = 0;
  }
// end convert_from_v8 block
  baton->index = from_index;
// start convert_from_v8 block
  const git_diff_options * from_opts;
    if (info[3]->IsObject()) {
  from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[3]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  TreeToIndexWorker *worker = new TreeToIndexWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_tree", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("index", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("opts", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::TreeToIndexWorker::Execute() {
  int result = git_diff_tree_to_index(
&baton->diff,baton->repo,baton->old_tree,baton->index,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::TreeToIndexWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->diff != NULL) {
    // GitDiff baton->diff
       to = GitDiff::New((void *)baton->diff, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("old_tree"));
      workerArguments.push(GetFromPersistent("index"));
      workerArguments.push(GetFromPersistent("opts"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method treeToIndex has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param Tree new_tree
   * @param DiffOptions opts
    * @param Diff callback
   */
NAN_METHOD(GitDiff::TreeToTree) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  TreeToTreeBaton* baton = new TreeToTreeBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree;
    if (info[1]->IsObject()) {
  from_old_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[1]->ToObject())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
  baton->old_tree = from_old_tree;
// start convert_from_v8 block
  git_tree * from_new_tree;
    if (info[2]->IsObject()) {
  from_new_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[2]->ToObject())->GetValue();
  }
  else {
    from_new_tree = 0;
  }
// end convert_from_v8 block
  baton->new_tree = from_new_tree;
// start convert_from_v8 block
  const git_diff_options * from_opts;
    if (info[3]->IsObject()) {
  from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[3]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  TreeToTreeWorker *worker = new TreeToTreeWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_tree", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("new_tree", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("opts", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::TreeToTreeWorker::Execute() {
  int result = git_diff_tree_to_tree(
&baton->diff,baton->repo,baton->old_tree,baton->new_tree,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::TreeToTreeWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->diff != NULL) {
    // GitDiff baton->diff
       to = GitDiff::New((void *)baton->diff, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("old_tree"));
      workerArguments.push(GetFromPersistent("new_tree"));
      workerArguments.push(GetFromPersistent("opts"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method treeToTree has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param DiffOptions opts
    * @param Diff callback
   */
NAN_METHOD(GitDiff::TreeToWorkdir) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  TreeToWorkdirBaton* baton = new TreeToWorkdirBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree;
    if (info[1]->IsObject()) {
  from_old_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[1]->ToObject())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
  baton->old_tree = from_old_tree;
// start convert_from_v8 block
  const git_diff_options * from_opts;
    if (info[2]->IsObject()) {
  from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[2]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  TreeToWorkdirWorker *worker = new TreeToWorkdirWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_tree", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("opts", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::TreeToWorkdirWorker::Execute() {
  int result = git_diff_tree_to_workdir(
&baton->diff,baton->repo,baton->old_tree,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::TreeToWorkdirWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->diff != NULL) {
    // GitDiff baton->diff
       to = GitDiff::New((void *)baton->diff, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("old_tree"));
      workerArguments.push(GetFromPersistent("opts"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method treeToWorkdir has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

  
/*
  * @param Repository repo
   * @param Tree old_tree
   * @param DiffOptions opts
    * @param Diff callback
   */
NAN_METHOD(GitDiff::TreeToWorkdirWithIndex) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  TreeToWorkdirWithIndexBaton* baton = new TreeToWorkdirWithIndexBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_tree * from_old_tree;
    if (info[1]->IsObject()) {
  from_old_tree = Nan::ObjectWrap::Unwrap<GitTree>(info[1]->ToObject())->GetValue();
  }
  else {
    from_old_tree = 0;
  }
// end convert_from_v8 block
  baton->old_tree = from_old_tree;
// start convert_from_v8 block
  const git_diff_options * from_opts;
    if (info[2]->IsObject()) {
  from_opts = Nan::ObjectWrap::Unwrap<GitDiffOptions>(info[2]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  TreeToWorkdirWithIndexWorker *worker = new TreeToWorkdirWithIndexWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("old_tree", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("opts", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitDiff::TreeToWorkdirWithIndexWorker::Execute() {
  int result = git_diff_tree_to_workdir_with_index(
&baton->diff,baton->repo,baton->old_tree,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitDiff::TreeToWorkdirWithIndexWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->diff != NULL) {
    // GitDiff baton->diff
       to = GitDiff::New((void *)baton->diff, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("old_tree"));
      workerArguments.push(GetFromPersistent("opts"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method treeToWorkdirWithIndex has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

      Nan::Persistent<Function> GitDiff::constructor_template;
 