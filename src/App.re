open Css;

module Query = [%relay.query
  {|
    query AppQuery {
      __typename
    }
  |}
];

let baseStyle =
  merge([
    style([
      height(`vh(100.0))
    ]),
    "base-style"
  ]);

[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();

  let page =
    switch(url.path){
    | [] => <Home />
    | ["login"] => <div>{"Login" |> ReasonReact.string}</div>
    | _ => <div>{"Page not found" |> ReasonReact.string}</div>
    };

  let loading = <Loading />;
    <div className=baseStyle>
      <ReactExperimental.Suspense fallback=loading>
        page
      </ReactExperimental.Suspense>
    </div>
}