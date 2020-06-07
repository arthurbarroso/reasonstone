open Css;

let linkColor = (isHovering: bool) => isHovering ? hex("fcba03") : hex("333")
let linkSize = (strong: bool) => strong ? px(32) : px(16);

let linkStyle = (isHovering: bool, strong: bool) => {
  let usedColor = linkColor(isHovering);
  let usedSize = linkSize(strong);

  merge([
    style([
      fontSize(usedSize),
      color(usedColor),
      marginRight(px(6)),
      cursor(`pointer)
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
let make = (~name, ~href, ~strong=false) => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
          | ToggleHover => {isHovering: !state.isHovering}
        },
      {isHovering: false},
    );



  strong ? 
      <h1
        onMouseOver={_event => dispatch(ToggleHover)}
        onMouseOut={_event => dispatch(ToggleHover)} 
        className=linkStyle(state.isHovering, strong) 
        onClick={handleClick(href)}>{name |> ReasonReact.string}
      </h1>
    : 
      <a
        onMouseOver={_event => dispatch(ToggleHover)}
        onMouseOut={_event => dispatch(ToggleHover)} 
        className=linkStyle(state.isHovering, strong) 
        onClick={handleClick(href)}>{name |> ReasonReact.string}
      </a>
}