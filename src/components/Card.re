[@react.component]

let make = (~name: option(string)=?, ~text: option(string)=?, ~image: option(string)=?, ~manaCost: option(string)=?) => {
  let cardName =
    switch(name){
      | None => React.null;
      | Some(name) => <h1>{ReasonReact.string(name)}</h1>
    };
  
  let cardText =
    switch(text){
      | None => React.null;
      | Some(text) => <p>{ReasonReact.string(text)}</p>
    };

  let cardImg =
    switch(image){
      | None => React.null;
      | Some(image) => <img src=image alt="card-image" />
    };
  
  let cardMana =
    switch(manaCost){
      | None => React.null;
      | Some(manaCost) => <p>{ReasonReact.string(manaCost)}</p>
    };

    <div>
      cardName
      cardImg
      cardMana
      cardText
    </div>
}