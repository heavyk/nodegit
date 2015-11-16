// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/attr.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitAttr::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "addMacro", AddMacro);
         Nan::SetMethod(object, "cacheFlush", CacheFlush);
         Nan::SetMethod(object, "get", Get);
         Nan::SetMethod(object, "getMany", GetMany);
         Nan::SetMethod(object, "value", Value);
  
    Nan::Set(target, Nan::New<String>("Attr").ToLocalChecked(), object);
  }

  
/*
 * @param Repository repo
   * @param String name
   * @param String values
     * @return Number  result    */
NAN_METHOD(GitAttr::AddMacro) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String values is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_values;

  String::Utf8Value values(info[2]->ToString());
  from_values = (const char *) strdup(*values);
// end convert_from_v8 block
   int result = git_attr_add_macro(
from_repo
,from_name
,from_values
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
     */
NAN_METHOD(GitAttr::CacheFlush) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 git_attr_cache_flush(
from_repo
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
  
/*
  * @param Repository repo
   * @param Number flags
   * @param String path
   * @param String name
    * @param String callback
   */
NAN_METHOD(GitAttr::Get) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 3 || !info[3]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 4 || !info[4]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetBaton* baton = new GetBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
  baton->flags = from_flags;
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[2]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[3]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
  baton->name = from_name;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[4]));
  GetWorker *worker = new GetWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("flags", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("path", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("name", info[3]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitAttr::GetWorker::Execute() {
  int result = git_attr_get(
&baton->value_out,baton->repo,baton->flags,baton->path,baton->name    );

}

void GitAttr::GetWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->value_out){
       to = Nan::New<String>(baton->value_out).ToLocalChecked();
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
      workerArguments.push(GetFromPersistent("flags"));
      workerArguments.push(GetFromPersistent("path"));
      workerArguments.push(GetFromPersistent("name"));
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
        Local<v8::Object> err = Nan::Error("Method get has thrown an error.")->ToObject();
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

  free((void *)baton->value_out);
  free((void *)baton->path);
  free((void *)baton->name);

  delete baton;
}

   
/*
  * @param Repository repo
   * @param Number flags
   * @param String path
   * @param Number num_attr
   * @param String names
     * @return Array values_out    */
NAN_METHOD(GitAttr::GetMany) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number flags is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number num_attr is required.");
  }

  if (info.Length() == 4 || !info[4]->IsString()) {
    return Nan::ThrowError("String names is required.");
  }

  const char * values_out = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  uint32_t from_flags;
  from_flags = (uint32_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[2]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
// start convert_from_v8 block
  size_t from_num_attr;
  from_num_attr = (size_t)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char ** from_names;

  String::Utf8Value names(info[4]->ToString());
  from_names = (const char **) strdup(*names);
// end convert_from_v8 block
   int result = git_attr_get_many(
&values_out
,from_repo
,from_flags
,from_path
,from_num_attr
,from_names
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  if (values_out){
       to = Nan::New<String>(values_out).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param String attr
     * @return Number  result    */
NAN_METHOD(GitAttr::Value) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String attr is required.");
  }

// start convert_from_v8 block
  const char * from_attr;

  String::Utf8Value attr(info[0]->ToString());
  from_attr = (const char *) strdup(*attr);
// end convert_from_v8 block
   git_attr_t result = git_attr_value(
from_attr
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitAttr::constructor_template;
 