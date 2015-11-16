// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/config.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/git_buf_converter.h"
  #include "../include/buf.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitConfig::GitConfig(git_config *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitConfig::~GitConfig() {
      if (this->selfFreeing) {
        git_config_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                               }

  void GitConfig::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Config").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "getStringBuf", GetStringBuf);
             Nan::SetMethod(tpl, "openDefault", OpenDefault);
            Nan::SetPrototypeMethod(tpl, "setInt64", SetInt64);
            Nan::SetPrototypeMethod(tpl, "setMultivar", SetMultivar);
            Nan::SetPrototypeMethod(tpl, "setString", SetString);
            Nan::SetPrototypeMethod(tpl, "snapshot", Snapshot);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Config").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitConfig::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitConfig cannot be instantiated.");
     }

    GitConfig* object = new GitConfig(static_cast<git_config *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitConfig::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitConfig::constructor_template), 2, argv).ToLocalChecked());
  }

  git_config *GitConfig::GetValue() {
    return this->raw;
  }

  git_config **GitConfig::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitConfig::ClearValue() {
    this->raw = NULL;
  }

 
/*
    * @param String name
    * @param Buf callback
   */
NAN_METHOD(GitConfig::GetStringBuf) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  GetStringBufBaton* baton = new GetStringBufBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

      baton->out = (git_buf *)malloc(sizeof(git_buf ));;
      baton->out->ptr = NULL;
      baton->out->size = baton->out->asize = 0;
  baton->cfg = Nan::ObjectWrap::Unwrap<GitConfig>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
  baton->name = from_name;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  GetStringBufWorker *worker = new GetStringBufWorker(baton, callback);
  worker->SaveToPersistent("cfg", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("name", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitConfig::GetStringBufWorker::Execute() {
  int result = git_config_get_string_buf(
baton->out,baton->cfg,baton->name    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitConfig::GetStringBufWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  if (baton->out) {
    to = Nan::New<String>(baton->out->ptr, baton->out->size).ToLocalChecked();
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
        Local<v8::Object> err = Nan::Error("Method getStringBuf has thrown an error.")->ToObject();
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

  git_buf_free(baton->out);
  free((void *)baton->out);
  free((void *)baton->name);

  delete baton;
}

  
/*
   * @param Config callback
   */
NAN_METHOD(GitConfig::OpenDefault) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenDefaultBaton* baton = new OpenDefaultBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;


  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  OpenDefaultWorker *worker = new OpenDefaultWorker(baton, callback);

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitConfig::OpenDefaultWorker::Execute() {
  int result = git_config_open_default(
&baton->out    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitConfig::OpenDefaultWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitConfig baton->out
       to = GitConfig::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method openDefault has thrown an error.")->ToObject();
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
   * @param String name
   * @param Number value
     * @return Number  result    */
NAN_METHOD(GitConfig::SetInt64) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number value is required.");
  }

// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  int64_t from_value;
  from_value = (int64_t)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_config_set_int64(
Nan::ObjectWrap::Unwrap<GitConfig>(info.This())->GetValue()
,from_name
,from_value
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String name
   * @param String regexp
   * @param String value
     * @return Number  result    */
NAN_METHOD(GitConfig::SetMultivar) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String regexp is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String value is required.");
  }

// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_regexp;

  String::Utf8Value regexp(info[1]->ToString());
  from_regexp = (const char *) strdup(*regexp);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_value;

  String::Utf8Value value(info[2]->ToString());
  from_value = (const char *) strdup(*value);
// end convert_from_v8 block
   int result = git_config_set_multivar(
Nan::ObjectWrap::Unwrap<GitConfig>(info.This())->GetValue()
,from_name
,from_regexp
,from_value
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
   * @param String name
   * @param String value
     */
NAN_METHOD(GitConfig::SetString) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String value is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SetStringBaton* baton = new SetStringBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->cfg = Nan::ObjectWrap::Unwrap<GitConfig>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[0]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
  baton->name = from_name;
// start convert_from_v8 block
  const char * from_value;

  String::Utf8Value value(info[1]->ToString());
  from_value = (const char *) strdup(*value);
// end convert_from_v8 block
  baton->value = from_value;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  SetStringWorker *worker = new SetStringWorker(baton, callback);
  worker->SaveToPersistent("cfg", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("name", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("value", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitConfig::SetStringWorker::Execute() {
  int result = git_config_set_string(
baton->cfg,baton->name,baton->value    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitConfig::SetStringWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("name"));
      workerArguments.push(GetFromPersistent("value"));
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
        Local<v8::Object> err = Nan::Error("Method setString has thrown an error.")->ToObject();
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

  free((void *)baton->name);
  free((void *)baton->value);

  delete baton;
}

  
/*
     * @param Config callback
   */
NAN_METHOD(GitConfig::Snapshot) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  SnapshotBaton* baton = new SnapshotBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->config = Nan::ObjectWrap::Unwrap<GitConfig>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  SnapshotWorker *worker = new SnapshotWorker(baton, callback);
  worker->SaveToPersistent("config", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitConfig::SnapshotWorker::Execute() {
  int result = git_config_snapshot(
&baton->out,baton->config    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitConfig::SnapshotWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitConfig baton->out
       to = GitConfig::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method snapshot has thrown an error.")->ToObject();
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

      Nan::Persistent<Function> GitConfig::constructor_template;
 