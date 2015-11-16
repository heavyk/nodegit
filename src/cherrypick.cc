// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cherrypick.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
  #include "../include/commit.h"
  #include "../include/cherrypick_options.h"
  #include "../include/index.h"
  #include "../include/merge_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitCherrypick::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "cherrypick", Cherrypick);
         Nan::SetMethod(object, "commit", Commit);
         Nan::SetMethod(object, "initOptions", InitOptions);
  
    Nan::Set(target, Nan::New<String>("Cherrypick").ToLocalChecked(), object);
  }

 
/*
 * @param Repository repo
   * @param Commit commit
   * @param CherrypickOptions cherrypick_options
     */
NAN_METHOD(GitCherrypick::Cherrypick) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Commit commit is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("CherrypickOptions cherrypick_options is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CherrypickBaton* baton = new CherrypickBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_commit * from_commit;
  from_commit = Nan::ObjectWrap::Unwrap<GitCommit>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->commit = from_commit;
// start convert_from_v8 block
  const git_cherrypick_options * from_cherrypick_options;
  from_cherrypick_options = Nan::ObjectWrap::Unwrap<GitCherrypickOptions>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->cherrypick_options = from_cherrypick_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  CherrypickWorker *worker = new CherrypickWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("commit", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("cherrypick_options", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCherrypick::CherrypickWorker::Execute() {
  int result = git_cherrypick(
baton->repo,baton->commit,baton->cherrypick_options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCherrypick::CherrypickWorker::HandleOKCallback() {
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
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("commit"));
      workerArguments.push(GetFromPersistent("cherrypick_options"));
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
        Local<v8::Object> err = Nan::Error("Method cherrypick has thrown an error.")->ToObject();
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
   * @param Commit cherrypick_commit
   * @param Commit our_commit
   * @param Number mainline
   * @param MergeOptions merge_options
    * @param Index callback
   */
NAN_METHOD(GitCherrypick::Commit) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Commit cherrypick_commit is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("Commit our_commit is required.");
  }

  if (info.Length() == 3 || !info[3]->IsNumber()) {
    return Nan::ThrowError("Number mainline is required.");
  }

  if (info.Length() == 4 || !info[4]->IsObject()) {
    return Nan::ThrowError("MergeOptions merge_options is required.");
  }

  if (info.Length() == 5 || !info[5]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  CommitBaton* baton = new CommitBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  git_commit * from_cherrypick_commit;
  from_cherrypick_commit = Nan::ObjectWrap::Unwrap<GitCommit>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->cherrypick_commit = from_cherrypick_commit;
// start convert_from_v8 block
  git_commit * from_our_commit;
  from_our_commit = Nan::ObjectWrap::Unwrap<GitCommit>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->our_commit = from_our_commit;
// start convert_from_v8 block
  unsigned int from_mainline;
  from_mainline = (unsigned int)   info[3]->ToNumber()->Value();
// end convert_from_v8 block
  baton->mainline = from_mainline;
// start convert_from_v8 block
  const git_merge_options * from_merge_options;
  from_merge_options = Nan::ObjectWrap::Unwrap<GitMergeOptions>(info[4]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->merge_options = from_merge_options;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[5]));
  CommitWorker *worker = new CommitWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("cherrypick_commit", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("our_commit", info[2]->ToObject());
  if (!info[3]->IsUndefined() && !info[3]->IsNull())
    worker->SaveToPersistent("mainline", info[3]->ToObject());
  if (!info[4]->IsUndefined() && !info[4]->IsNull())
    worker->SaveToPersistent("merge_options", info[4]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitCherrypick::CommitWorker::Execute() {
  int result = git_cherrypick_commit(
&baton->out,baton->repo,baton->cherrypick_commit,baton->our_commit,baton->mainline,baton->merge_options    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitCherrypick::CommitWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitIndex baton->out
       to = GitIndex::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("cherrypick_commit"));
      workerArguments.push(GetFromPersistent("our_commit"));
      workerArguments.push(GetFromPersistent("mainline"));
      workerArguments.push(GetFromPersistent("merge_options"));
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
        Local<v8::Object> err = Nan::Error("Method commit has thrown an error.")->ToObject();
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
 * @param CherrypickOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitCherrypick::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("CherrypickOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_cherrypick_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitCherrypickOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_cherrypick_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitCherrypick::constructor_template;
 