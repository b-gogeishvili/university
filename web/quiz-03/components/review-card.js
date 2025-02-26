class ReviewCard extends HTMLElement {
    constructor() {
        super();
        this.attachShadow({ mode: 'open' });
        this.shadowRoot.innerHTML = `
            <style>
                .card {
                    border: 1px solid #ccc;
                    border-radius: 8px;
                    padding: 16px;
                    margin: 8px;
                    background-color: #fff;
                    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
                }
                .name {
                    font-size: 1em;
                    margin: 0;
                }
                .email {
                    font-size: 0.9em;
                    color: #666;
                }
            </style>
            <div class="card">
                <p class="name"></p>
                <p class="email"></p>
            </div>
        `;
    }

    connectedCallback() {
        this.shadowRoot.querySelector('.name').textContent = this.getAttribute('name');
        this.shadowRoot.querySelector('.email').textContent = this.getAttribute('email');
    }
}

customElements.define('review-card', ReviewCard);
