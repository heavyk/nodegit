// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/clone.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
  #include "../include/clone_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitClone::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "clone", Clone);
         Nan::SetMethod(object, "initOptions", InitOptions);
  
    Nan::Set(target, Nan::New<String>("Clone").ToLocalChecked(), object);
  }

 
/*
  * @param String url
   * @param String local_path
   * @param CloneOptions options
    * @param Repository callback
   */
NAN_METHOD(GitClone::Clone) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String url is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String local_path is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CloneBaton* baton = new CloneBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  const char * from_url;

  String::Utf8Value url(info[0]->ToString());
  from_url = (const char *) strdup(*url);
// end convert_from_v8 block
  baton->url = from_url;
// start convert_from_v8 block
  const char * from_local_path;

  String::Utf8Value local_path(info[1]->ToString());
  from_local_path = (const char *) strdup(*local_path);
// end convert_from_v8 block
  baton->local_path = from_local_path;
// start convert_from_v8 block
  const git_clone_options * from_options;
    if (info[2]->IsObject()) {
  from_options = Nan::ObjectWrap::Unwrap<GitCloneOptions>(info[2]->ToObject())->GetValue();
  }
  else {
    from_options = 0;
  }
// end convert_from_v8 block
  baton->options = from_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  CloneWorker *worker = new CloneWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("url", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("local_path", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("options", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitClone::CloneWorker::Execute() {
  int result = git_clone(
&baton->out,baton->url,baton->local_path,baton->options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitClone::CloneWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRepository baton->out
       to = GitRepository::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("url"));
      workerArguments.push(GetFromPersistent("local_path"));
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
        Local<v8::Object> err = Nan::Error("Method clone has thrown an error.")->ToObject();
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

  free((void *)baton->url);
  free((void *)baton->local_path);

  delete baton;
}

   
/*
 * @param CloneOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitClone::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("CloneOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_clone_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitCloneOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_clone_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitClone::constructor_template;
 