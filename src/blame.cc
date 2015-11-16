// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/blame.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
  #include "../include/blame_options.h"
  #include "../include/blame_hunk.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitBlame::GitBlame(git_blame *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitBlame::~GitBlame() {
      if (this->selfFreeing) {
        git_blame_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                 }

  void GitBlame::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Blame").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "buffer", Buffer);
             Nan::SetMethod(tpl, "file", File);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "getHunkByIndex", GetHunkByindex);
            Nan::SetPrototypeMethod(tpl, "getHunkByLine", GetHunkByline);
            Nan::SetPrototypeMethod(tpl, "getHunkCount", GetHunkCount);
             Nan::SetMethod(tpl, "initOptions", InitOptions);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Blame").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitBlame::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitBlame cannot be instantiated.");
     }

    GitBlame* object = new GitBlame(static_cast<git_blame *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitBlame::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitBlame::constructor_template), 2, argv).ToLocalChecked());
  }

  git_blame *GitBlame::GetValue() {
    return this->raw;
  }

  git_blame **GitBlame::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitBlame::ClearValue() {
    this->raw = NULL;
  }

 
/*
    * @param String buffer
   * @param Number buffer_len
    * @param Blame callback
   */
NAN_METHOD(GitBlame::Buffer) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String buffer is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number buffer_len is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  BufferBaton* baton = new BufferBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->reference = Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_buffer;

  String::Utf8Value buffer(info[0]->ToString());
  from_buffer = (const char *) strdup(*buffer);
// end convert_from_v8 block
  baton->buffer = from_buffer;
// start convert_from_v8 block
  size_t from_buffer_len;
  from_buffer_len = (size_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->buffer_len = from_buffer_len;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  BufferWorker *worker = new BufferWorker(baton, callback);
  worker->SaveToPersistent("reference", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("buffer", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("buffer_len", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBlame::BufferWorker::Execute() {
  int result = git_blame_buffer(
&baton->out,baton->reference,baton->buffer,baton->buffer_len    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBlame::BufferWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitBlame baton->out
       to = GitBlame::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("buffer"));
      workerArguments.push(GetFromPersistent("buffer_len"));
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
        Local<v8::Object> err = Nan::Error("Method buffer has thrown an error.")->ToObject();
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

  free((void *)baton->buffer);

  delete baton;
}

  
/*
  * @param Repository repo
   * @param String path
   * @param BlameOptions options
    * @param Blame callback
   */
NAN_METHOD(GitBlame::File) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("BlameOptions options is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  FileBaton* baton = new FileBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[1]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  git_blame_options * from_options;
  from_options = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->options = from_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  FileWorker *worker = new FileWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("path", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("options", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitBlame::FileWorker::Execute() {
  int result = git_blame_file(
&baton->out,baton->repo,baton->path,baton->options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitBlame::FileWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitBlame baton->out
       to = GitBlame::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("path"));
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
        Local<v8::Object> err = Nan::Error("Method file has thrown an error.")->ToObject();
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

  free((void *)baton->path);

  delete baton;
}

   
/*
     */
NAN_METHOD(GitBlame::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->GetValue() != NULL) {
 git_blame_free(
Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
   * @param Number index
     * @return BlameHunk  result    */
NAN_METHOD(GitBlame::GetHunkByindex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number index is required.");
  }

// start convert_from_v8 block
  uint32_t from_index;
  from_index = (uint32_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_blame_hunk * result = git_blame_get_hunk_byindex(
Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->GetValue()
,from_index
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitBlameHunk result
       to = GitBlameHunk::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number lineno
     * @return BlameHunk  result    */
NAN_METHOD(GitBlame::GetHunkByline) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number lineno is required.");
  }

// start convert_from_v8 block
  uint32_t from_lineno;
  from_lineno = (uint32_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_blame_hunk * result = git_blame_get_hunk_byline(
Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->GetValue()
,from_lineno
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitBlameHunk result
       to = GitBlameHunk::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitBlame::GetHunkCount) {
  Nan::EscapableHandleScope scope;

   uint32_t result = git_blame_get_hunk_count(
Nan::ObjectWrap::Unwrap<GitBlame>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param BlameOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitBlame::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("BlameOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_blame_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitBlameOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_blame_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitBlame::constructor_template;
 