// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/rebase.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/repository.h"
  #include "../include/annotated_commit.h"
  #include "../include/rebase_options.h"
  #include "../include/rebase_operation.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRebase::GitRebase(git_rebase *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitRebase::~GitRebase() {
      if (this->selfFreeing) {
        git_rebase_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                 }

  void GitRebase::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Rebase").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "abort", Abort);
            Nan::SetPrototypeMethod(tpl, "commit", Commit);
            Nan::SetPrototypeMethod(tpl, "finish", Finish);
             Nan::SetMethod(tpl, "init", Init);
             Nan::SetMethod(tpl, "initOptions", InitOptions);
            Nan::SetPrototypeMethod(tpl, "next", Next);
             Nan::SetMethod(tpl, "open", Open);
            Nan::SetPrototypeMethod(tpl, "operationByIndex", OperationByindex);
            Nan::SetPrototypeMethod(tpl, "operationCurrent", OperationCurrent);
            Nan::SetPrototypeMethod(tpl, "operationEntrycount", OperationEntrycount);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Rebase").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitRebase::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitRebase cannot be instantiated.");
     }

    GitRebase* object = new GitRebase(static_cast<git_rebase *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitRebase::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitRebase::constructor_template), 2, argv).ToLocalChecked());
  }

  git_rebase *GitRebase::GetValue() {
    return this->raw;
  }

  git_rebase **GitRebase::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitRebase::ClearValue() {
    this->raw = NULL;
  }

  
/*
     * @return Number  result    */
NAN_METHOD(GitRebase::Abort) {
  Nan::EscapableHandleScope scope;

   int result = git_rebase_abort(
Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
    * @param Signature author
   * @param Signature committer
   * @param String message_encoding
   * @param String message
     * @return Oid id    */
NAN_METHOD(GitRebase::Commit) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  git_oid *id = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  const git_signature * from_author;
    if (info[0]->IsObject()) {
  from_author = Nan::ObjectWrap::Unwrap<GitSignature>(info[0]->ToObject())->GetValue();
  }
  else {
    from_author = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer;
  from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message_encoding;
    if (info[2]->IsString()) {

  String::Utf8Value message_encoding(info[2]->ToString());
  from_message_encoding = (const char *) strdup(*message_encoding);
  }
  else {
    from_message_encoding = 0;
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_message;
    if (info[3]->IsString()) {

  String::Utf8Value message(info[3]->ToString());
  from_message = (const char *) strdup(*message);
  }
  else {
    from_message = 0;
  }
// end convert_from_v8 block
   int result = git_rebase_commit(
id
,Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue()
,from_author
,from_committer
,from_message_encoding
,from_message
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (id != NULL) {
    // GitOid id
       to = GitOid::New((void *)id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Signature signature
     * @return Number  result    */
NAN_METHOD(GitRebase::Finish) {
  Nan::EscapableHandleScope scope;

// start convert_from_v8 block
  const git_signature * from_signature;
    if (info[0]->IsObject()) {
  from_signature = Nan::ObjectWrap::Unwrap<GitSignature>(info[0]->ToObject())->GetValue();
  }
  else {
    from_signature = 0;
  }
// end convert_from_v8 block
   int result = git_rebase_finish(
Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue()
,from_signature
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
  * @param Repository repo
   * @param AnnotatedCommit branch
   * @param AnnotatedCommit upstream
   * @param AnnotatedCommit onto
   * @param RebaseOptions opts
    * @param Rebase callback
   */
NAN_METHOD(GitRebase::Init) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("AnnotatedCommit branch is required.");
  }

  if (info.Length() == 5 || !info[5]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  InitBaton* baton = new InitBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_annotated_commit * from_branch;
  from_branch = Nan::ObjectWrap::Unwrap<GitAnnotatedCommit>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->branch = from_branch;
// start convert_from_v8 block
  const git_annotated_commit * from_upstream;
    if (info[2]->IsObject()) {
  from_upstream = Nan::ObjectWrap::Unwrap<GitAnnotatedCommit>(info[2]->ToObject())->GetValue();
  }
  else {
    from_upstream = 0;
  }
// end convert_from_v8 block
  baton->upstream = from_upstream;
// start convert_from_v8 block
  const git_annotated_commit * from_onto;
    if (info[3]->IsObject()) {
  from_onto = Nan::ObjectWrap::Unwrap<GitAnnotatedCommit>(info[3]->ToObject())->GetValue();
  }
  else {
    from_onto = 0;
  }
// end convert_from_v8 block
  baton->onto = from_onto;
// start convert_from_v8 block
  const git_rebase_options * from_opts;
    if (info[4]->IsObject()) {
  from_opts = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info[4]->ToObject())->GetValue();
  }
  else {
    from_opts = 0;
  }
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[5]));
  InitWorker *worker = new InitWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("branch", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("upstream", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("onto", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("opts", info[4]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRebase::InitWorker::Execute() {
  int result = git_rebase_init(
&baton->out,baton->repo,baton->branch,baton->upstream,baton->onto,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRebase::InitWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRebase baton->out
       to = GitRebase::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("branch"));
      workerArguments.push(GetFromPersistent("upstream"));
      workerArguments.push(GetFromPersistent("onto"));
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
        Local<v8::Object> err = Nan::Error("Method init has thrown an error.")->ToObject();
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
 * @param RebaseOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitRebase::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("RebaseOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_rebase_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_rebase_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param RebaseOperation callback
   */
NAN_METHOD(GitRebase::Next) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  NextBaton* baton = new NextBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->rebase = Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  NextWorker *worker = new NextWorker(baton, callback);
  worker->SaveToPersistent("rebase", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRebase::NextWorker::Execute() {
  int result = git_rebase_next(
&baton->out,baton->rebase    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRebase::NextWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRebaseOperation baton->out
       to = GitRebaseOperation::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method next has thrown an error.")->ToObject();
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
   * @param RebaseOptions opts
    * @param Rebase callback
   */
NAN_METHOD(GitRebase::Open) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("RebaseOptions opts is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  OpenBaton* baton = new OpenBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_rebase_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->opts = from_opts;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  OpenWorker *worker = new OpenWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("opts", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRebase::OpenWorker::Execute() {
  int result = git_rebase_open(
&baton->out,baton->repo,baton->opts    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRebase::OpenWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitRebase baton->out
       to = GitRebase::New((void *)baton->out, false);
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
        Local<v8::Object> err = Nan::Error("Method open has thrown an error.")->ToObject();
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
     * @return RebaseOperation  result    */
NAN_METHOD(GitRebase::OperationByindex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   git_rebase_operation * result = git_rebase_operation_byindex(
Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue()
,from_idx
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRebaseOperation result
       to = GitRebaseOperation::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRebase::OperationCurrent) {
  Nan::EscapableHandleScope scope;

   size_t result = git_rebase_operation_current(
Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRebase::OperationEntrycount) {
  Nan::EscapableHandleScope scope;

   size_t result = git_rebase_operation_entrycount(
Nan::ObjectWrap::Unwrap<GitRebase>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitRebase::constructor_template;
 