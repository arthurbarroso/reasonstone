open Css;

module Query = [%relay.query
  {|
  query AppQuery {
    ...Cards_query
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

  let query = Query.use(~variables=(), ());

  let page =
    switch(url.path){
    | [] => <Home query={query.getFragmentRefs()} />
    | ["login"] => <div>{"Login" |> ReasonReact.string}</div>
    | _ => <div>{"Page not found" |> ReasonReact.string}</div>
    };
    <div className=baseStyle>
        page
    </div>
}