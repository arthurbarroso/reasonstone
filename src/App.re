[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();

  let page =
    switch(url.path){
    | [] => <Home />
    | ["login"] => <div>{"Login" |> ReasonReact.string}</div>
    | _ => <div>{"Page not found" |> ReasonReact.string}</div>
    };

  page
}