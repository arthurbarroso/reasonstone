open Css;

let navbarContainer = 
  merge([
    style([background(rgb(251, 243, 197)), display(flexBox), width(auto)]),
      "navbar-container"
    ]);

[@react.component]
let make = () => {
  <div className=navbarContainer>
    <h1>{ReasonReact.string("Arthur")}</h1>
  </div>
};

