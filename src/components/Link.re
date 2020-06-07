open Css;

let linkColor = (isHovering: bool) => isHovering ? hex("000666") : hex("333")

let linkStyle = (isHovering: bool) => {
  let usedColor = linkColor(isHovering);

  merge([
    style([
      fontSize(px(18)),
      color(usedColor),
    ]),
    "link-style"
  ])
}

let handleClick = (href, _event) => {
  ReasonReactRouter.push(href);
};

type state = {isHovering: bool};
type action =
  | ToggleHover;

[@react.component]
let make = (~name, ~href) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
          | ToggleHover => {isHovering: !state.isHovering}
        },
      {isHovering: false},
    );



  <a onMouseOver={_event => dispatch(ToggleHover)} 
    onMouseOut={_event => dispatch(ToggleHover)} 
    className=linkStyle(state.isHovering) 
    onClick={handleClick(href)}>{name |> ReasonReact.string}
  </a>
}