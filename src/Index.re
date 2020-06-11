
  let loading = <Loading />;

// ReactDOMRe.renderToElementWithId(<App />, "root");
  ReactExperimental.renderConcurrentRootAtElementWithId(
    <ReasonRelay.Context.Provider environment=RelayEnv.environment>
      <ReactExperimental.Suspense fallback=loading>
        <App />
      </ReactExperimental.Suspense>
    </ReasonRelay.Context.Provider>,
    "root",
  );